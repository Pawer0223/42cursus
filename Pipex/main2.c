/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/24 22:11:42 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		fill_buf(int fds[2])
{
	char *words[] = {"pear", "peach", "apple"};
	// write input to the writable file descriptor so it can be read in from child:
	size_t numwords = sizeof(words) / sizeof(words[0]);
	for (size_t i = 0; i < numwords; i++)
	{
		dprintf(fds[1], "%s\n", words[i]);
	}
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
	{
		write(fds[1], buf, BUFFER_SIZE);
	}
	return (1);
}

int first(const char *file, char **param)
{
	int		fds[2];         // an array that will hold two file descriptors
	int		status;
	pid_t	pid;
	pid_t	wpid;

	pipe(fds);          // populates fds with two file descriptors
	input_pipe_fill(file, fds);
	pid = fork(); // create child process that is a clone of the parent


	// child process
	if (pid == 0)
	{
		dup2(fds[0], STDIN_FILENO); // 표준 입력이 pipe[0]이 됨.
		close(fds[0]); // dup2에 의해 표준 입력이 fds[0]을 가르키니깐, 기존 fd는 close해주기.
		close(fds[1]); // 자식 프로세스에는 읽기만하고, 쓰지는 않는다.

		if (execvp(param[0], param) < 0) // 표준입력(fds[0]을 바라봄)을 이용한, 명령어 수행.
			exit(0); // run sort command (exit if something went wrong)
	}
	// parent process
	close(fds[0]); // 부모프로세스에서는 파이프의 입력은 하지 않음.
	// 출력을 닫을 때, EOF가 전송되어 자식 프로세스에게 전송되었음을 알릴 수 있다.
	close(fds[1]);
	// 자식 프로세스가 종료된 후, signal을 받아야 함.
	// why? stdout이 닫힌 후, 부모프로세스로 복귀해야 함.
	wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
	return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}

int		temp(const char *file, const char *cmd, char *path)
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
	if (file)
		first(file, cmd_info);
	// free cmd_info
	return (1);
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
		temp(argv[1], argv[2], path);
	}
	return (1);
}