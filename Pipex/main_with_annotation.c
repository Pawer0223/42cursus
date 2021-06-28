// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
// /*   Updated: 2021/06/28 14:43:50 by taesan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// void	exec_command_print(char *param[], int pipefd[2], int flags)
// {
// 	pid_t cpid = fork();

// 	if (cpid > 0) // parent
// 	{
// 		printf("parent processing .... \n");
// 		return;
// 	}
// 	else if (cpid < 0) // error
// 		perror("fork");
// 	else // child
// 	{
// 		printf("child processing .... \n");
// 		char *const envp[] = {NULL};

// 		printf("flags : %d, flags & STDIN_PIPE : %d, flags & STDOUT_PIPE : %d\n"
// 		, flags, (flags & STDIN_PIPE),(flags & STDOUT_PIPE)
// 		);

// 		if (flags & STDIN_PIPE) {
// 			printf("[%s], STDIN_PIPE ... fd => [%d]\n", param[0], pipefd[0]);
// 			if (dup2(pipefd[0], STDIN_FILENO) < 0)
// 				perror("dup2");
// 		}

// 		if (flags & STDOUT_PIPE) {
// 			printf("[%s], STDOUT_PIPE ... fd => [%d]\n", param[0], pipefd[1]);
// 			if (dup2(pipefd[1], STDOUT_FILENO) < 0)
// 				perror("dup2");
// 		}
// 		printf("before close\n");
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		printf("before execve\n");
// 		execve(param[0], param, envp);
// 		perror("execv");
// 	}	
// }

// void	exec_command(char *param[], int pipefd[2], int flags, int final)
// {
// 	pid_t	cpid;

// 	cpid = fork();
// 	if (cpid > 0)
// 		return;
// 	else if (cpid < 0)
// 		perror("fork");
// 	char *const envp[] = {NULL};
// 	if (flags & STDIN_PIPE)
// 		if (dup2(pipefd[0], STDIN_FILENO) < 0)
// 			perror("dup2");
// 	if (flags & STDOUT_PIPE)
// 	{
// 		if (final != NO_FINAL)
// 		{
// 			if (dup2(final, STDOUT_FILENO) < 0)
// 				perror("dup2");
// 			close(final);
// 		}
// 		else if (dup2(pipefd[1], STDOUT_FILENO) < 0)
// 			perror("dup2");
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	execve(param[0], param, envp);
// 	perror("execv");
// }

// int		input_pipe_fill(const char *file, int fds[2])
// {
// 	int		fd;
// 	char	*buf;

// 	if ((fd = open(file, O_RDONLY)) == -1)
// 		return (error_occur_perror(INPUT_OPEN_ERR));
// 	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
// 	while (read(fd, buf, BUFFER_SIZE)) // need free check
// 		write(fds[WRITE_FD_PIPE], buf, BUFFER_SIZE);
// 	free(buf);
// 	return (1);
// }

// char		**get_cmd_info(const char *cmd, char *path)
// {
// 	char	**cmd_info;

// 	if (!(cmd_info = ft_split(cmd, ' ')))
// 		return (error_occur_std(SPLIT_ERR));
// 	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
// 	{
// 		split_free(cmd_info);
// 		return (error_occur_std(COMMAND_NOT_EXIST));
// 	}
// 	return (cmd_info);
// }

// /*
// 	** file1, cmd1, cmd2, file2
// 	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt
// */
// int		main(int argc, const char *argv[], char *envp[])
// {
// 	char	*path;
// 	int		pipe_1[2];         // an array that will hold two file descriptors
// 	int		pipe_2[2];
// 	int		status;
// 	char	**cmd_info;
// 	int		result_fd;
// 	int		connect_fds[2] = {pipe_1[0], pipe_2[1]};

// 	if (argc < 5)
// 		ft_putendl_fd(PARAM_ERR, 1); // printf modify
// 	else
// 	{
// 		if (!(path = set_path(envp)))
// 			return (error_occur_std(ENV_PATH_NOT_EXIST));
// 		pipe(pipe_1);
// 		pipe(pipe_2);
// 		if ((result_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 
// 										S_IRUSR | S_IWUSR)) == -1)
// 			return (error_occur_perror(OUTPUT_OPEN_ERR));
// 		// 첫번째 파이프에 데이터 쓰기.
// 		if (!(input_pipe_fill(argv[1], pipe_1)))
// 			return (0);
// 		close(pipe_1[1]);

// 		// printf("fds[0] : %d, fds[1] : %d, fds_2[0] : %d, fds_2[1] : %d\n", fds[0], fds[1], fds_2[0], fds_2[1]);

// 		// 파이프를 연결하기.
// 		// 첫번째 명령어를 pipe1에서 입력받아, pipe2로 출력하도록한다. 즉, pipe2를 채워준다.
		
// 		cmd_info = get_cmd_info(argv[2], path);
// 		exec_command(cmd_info, connect_fds, STDIN_PIPE | STDOUT_PIPE, NO_FINAL);
// 		close(pipe_1[0]);
// 		close(pipe_2[1]);

// 		// 마지막 명령어는 입력을 pipe2에서 받아 처리한다.
// 		split_free(cmd_info);
// 		cmd_info = get_cmd_info(argv[3], path);
// 		// exec_command(cmd_info, fds_2, STDIN_PIPE);
// 		exec_command(cmd_info, pipe_2, STDIN_PIPE | STDOUT_PIPE, result_fd);
		
// 		// 메모리 해제
// 		close(pipe_2[0]);
// 		close(result_fd);
// 		split_free(cmd_info);

// 		// 부모에서 자식 프로세스가 끝나기를 대기하는 코드.
// 		while (wait(&status) > 0);
// 	}
// 	return (1);
// }
