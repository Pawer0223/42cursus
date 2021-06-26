/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/26 18:03:53 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command_print(char *param[], int pipefd[2], int flags)
{
	pid_t cpid = fork();

	if (cpid > 0) // parent
		return;
	else if (cpid < 0) // error
		perror("fork");
	else // child
	{
		char *const envp[] = {NULL};

		printf("flags : %d, flags & STDIN_PIPE : %d, flags & STDOUT_PIPE : %d\n"
		, flags, (flags & STDIN_PIPE),(flags & STDOUT_PIPE)
		);

		if (flags & STDIN_PIPE) {
			printf("[%s], STDIN_PIPE ... fd => [%d]\n", param[0], pipefd[0]);
			if (dup2(pipefd[0], STDIN_FILENO) < 0)
				perror("dup2");
		}

		if (flags & STDOUT_PIPE) {
			printf("[%s], STDOUT_PIPE ... fd => [%d]\n", param[0], pipefd[1]);
			if (dup2(pipefd[1], STDOUT_FILENO) < 0)
				perror("dup2");
		}
		close(pipefd[0]);
		close(pipefd[1]);
		execve(param[0], param, envp);
		perror("execv");
	}	
}

void	exec_command(char *param[], int pipefd[2], int flags)
{
	printf("cmd : %s\n", param[0]);
	pid_t	cpid;

	cpid = fork();
	if (cpid > 0)
		return;
	else if (cpid < 0)
		perror("fork");

	char *const envp[] = {NULL};

	if (flags & STDIN_PIPE)
		if (dup2(pipefd[0], STDIN_FILENO) < 0)
			perror("dup2");
	if (flags & STDOUT_PIPE)
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			perror("dup2");
	close(pipefd[0]);
	close(pipefd[1]);
	execve(param[0], param, envp);
	perror("execv");
}

/*
	 pipe 이해하기..
*/
int		input_pipe_fill(const char *file, int fds[2])
{
	int		fd;
	char	*buf;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_occur());
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buf, BUFFER_SIZE))
		write(fds[WRITE_FD_PIPE], buf, BUFFER_SIZE);
	return (1);
}

char		**temp(const char *cmd, char *path)
{
	char	**cmd_info;

	if (!(cmd_info = ft_split(cmd, ' ')))
	{
		printf("cmd split error\n");
		return (0);
	}
	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
	{
		// 실행파일이 존재하지 않음.
		// free cmd_info
		return (0);
	}

	return (cmd_info);
}

/*
	** file1, cmd1, cmd2, file2
	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt
*/
int		main(int argc, const char *argv[], char *envp[])
{
	char	*path;

	if (argc < 5)
		printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
	else
	{
		if (!(path = set_path(envp)))
		{
			printf("path is not exist\n");
			return (0);
		}

		int	fds[2];         // an array that will hold two file descriptors
		int fds_2[2];
		int status;
		pipe(fds);          // populates fds with two file descriptors
		pipe(fds_2);


		// 첫번째 파이프에 데이터 쓰기.
		input_pipe_fill(argv[1], fds);
		close(fds[1]);

		char **cmd_info;



		printf("fds[0] : %d, fds[1] : %d, fds_2[0] : %d, fds_2[1] : %d\n", fds[0], fds[1], fds_2[0], fds_2[1]);
		

		// 두번 째 파이프를 입력 대기 상태로.
		cmd_info = temp(argv[2], path);
		exec_command_print(cmd_info, fds_2, STDIN_PIPE);
		close(fds_2[0]);
		// 파이프를 연결하기.
		int connect_fds[2] = {fds[0], fds_2[1]};

		split_free(cmd_info);
		cmd_info = temp(argv[3], path);
		exec_command_print(cmd_info, connect_fds, STDIN_PIPE | STDOUT_PIPE);
		close(fds[0]);
		close(fds_2[1]);

		// 부모에서 자식 프로세스가 끝나기를 대기하는 코드.
		while (wait(&status) > 0);
	}
	return (1);
}

// void three_inst()
// {
// 	int pipefd1[2], pipefd2[2];

// 	pipe(pipefd1);
// 	pipe(pipefd2);

// 	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
// 	close(pipefd1[1]);
// 	exec_command("/usr/bin/wc", pipefd2, STDIN_PIPE);
// 	close(pipefd2[0]);

// 	int temp_pipefd[] = {pipefd1[0], pipefd2[1]};
// 	exec_command("/usr/bin/wc", temp_pipefd, STDIN_PIPE | STDOUT_PIPE);

// 	close(pipefd1[0]);
// 	close(pipefd2[1]);

// 	int wstatus;
// 	while (wait(&wstatus) > 0);
// }