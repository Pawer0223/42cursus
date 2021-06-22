// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/errno.h>
// #include "pipex.h"

// #define STDIN_PIPE 0x1
// #define STDOUT_PIPE 0x2

// int			error_occur()
// {
// 	perror(strerror(errno));
// 	return (0);
// }

// void			split_free(char **data)
// {
// 	int i;

// 	if (!data || !*data)
// 		return ;
// 	i = 0;
// 	while (data[i])
// 		free(data[i++]);
// 	free(data);
// }

// char			*check_command(const char *path, char *cmd, int len)
// {
// 	char	**paths;
// 	char	*full_path;
// 	char	*new_cmd;
// 	int		i;

// 	if (!(paths = ft_split(path, ':')))
// 		return (0);
// 	if (!(new_cmd = (char *)malloc(sizeof(len + 1))))
// 		return (0);
// 	new_cmd[0] = '/';
// 	ft_strlcpy(new_cmd + 1, cmd, len + 1);
// 	i = 0;
// 	while (paths[i])
// 	{
// 		if (!(full_path = ft_strjoin(paths[i], new_cmd)))
// 		{
// 			split_free(paths);
// 			return (0);
// 		}
// 		if (access(full_path, X_OK) == 0)
// 			return (full_path);
// 		i++;
// 	}
// 	split_free(paths);
// 	return (0);
// }

// char		*set_path(char *envp[])
// {
// 	char *path;

// 	while (*envp)
// 	{
// 		path = *envp;
// 		if (ft_strlen(path) < 4)
// 			continue;

// 		if (path[0] == 'P' && path[1] == 'A' && path[2] == 'T' && path[3] == 'H')
// 		{
// 			path = *envp;
// 			return (path);
// 		}
// 		envp++;
// 	}
// 	return (0);
// }

// void exec_command(char *command, int pipefd[2], char **param, int flags)
// {
// 	pid_t cpid = fork();
	
// 	// 부모 프로세스 일 때
// 	if (cpid > 0)
// 	{
// 		printf("parent !\n");
// 		int	fd;

// 		if ((fd = open("ls.txt", O_RDONLY)) == -1)
// 			// return (error_occur());
// 			return ;
// 		// 표준입력을, 파이프의 출력과 연결한다.
// 		close(pipefd[0]);
// 		dup2(pipefd[1], STDIN_FILENO);
// 		close(pipefd[1]);

// 		int wstatus;
// 		while (wait(&wstatus) > 0);
// 	}
// 	else if (cpid < 0)
// 		perror("fork");

// 	// 자식 프로세스 일 때
// 	char *const envp[] = {NULL};

// 	// 표준, 입출력에 따른 파일 디스크립터 복사 작업.
// 	if (flags & STDIN_PIPE)
// 		if (dup2(pipefd[0], STDIN_FILENO) < 0)
// 			perror("dup2");

// 	if (flags & STDOUT_PIPE)
// 		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
// 			perror("dup2");

// 	// 프로세스 내에서만 쓰기 때문에, 닫아주고
// 	// 의문, 호출하기전에 닫으면.. 결과 받기도 전에 닫히는거 아님 ?
//     // 현재 파일이 표준 입력 or 출력으로 변환되 었음.
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	// 실제로 호출하는 코드
// 	execve(command, param, envp);

// 	// 에러일 때만 출력
// 	perror("execv");
// }

// int		pipe_input_set(int pipe_line[2], const char *file)
// {
// 	int	fd;

// 	if ((fd = open(file, O_RDONLY)) == -1)
// 		return (error_occur());
// 	// 표준입력을, 파이프의 출력과 연결한다.
// 	close(pipe_line[1]);
// 	pipe_line[1] = fd;
// 	dup2(pipe_line[1], STDIN_FILENO);
// 	// char *buffer = (char *)malloc(sizeof(char) * 10);
// 	// while (read(fd, buffer, 5)) {
// 	// 	printf("%s", buffer);
// 	// }

//   	// const char *words[] = {"pear", "peach", "apple"};
// 	// printf("%lu / %lu = %lu\n",sizeof(words), sizeof(words[0]), sizeof(words)/sizeof(words[0]));
// 	return (1);
// }

// void two_inst(char	**cmd_info, int	pipe_line[2], char flag, int idx)
// {
// 	char	*cmd;

// 	// 파이프 생성, 표준 입력, 출력에 대한 fd가 지정 됨.
// 	cmd = cmd_info[0];
// 	exec_command(cmd, pipe_line, cmd_info, flag);
// 	close(pipe_line[idx]);
// }

// int		temp(const char *cmd, char *path, int pipe_line[2], int seq)
// {
// 	char	**cmd_info;

// 	if (!(cmd_info = ft_split(cmd, ' ')))
// 	{
// 		printf("cmd split error\n");
// 		return (0);
// 	}
// 	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
// 	{
// 		// 실행파일이 존재하지 않음.
// 		// free cmd_info
// 		return (0);
// 	}
// 	printf("cmd : %s\n", cmd_info[0]);

// 	if (seq % 2 == 0)
// 		two_inst(cmd_info, pipe_line, STDOUT_PIPE, 1);
// 	else
// 		two_inst(cmd_info, pipe_line, STDIN_PIPE, 0);
// 	// free cmd_info
// 	return (1);
// }

// int		pipe_output_set(int pipe_line[2], const char *file)
// {
// 	pipe_line = 0;
// 	file = 0;
// 	// 파이프 닫고

// 	return (1);
// }
// /*
// 	** file1, cmd1, cmd2, file2
// 	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt
// */
// int		main(int argc, const char *argv[], char *envp[])
// {
// 	char	*path;
// 	int		pipe_line[2];

// 	if (argc < 5)
// 		printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
// 	else
// 	{
// 		if (!(path = set_path(envp)))
// 		{
// 			printf("path is not exist\n");
// 			return (0);
// 		}
// 		// 1.cmd파싱 -> 자식프로세스 실행 이어서 계속
// 		pipe(pipe_line);
// 		// if (pipe_input_set(pipe_line, argv[1]))
// 		// 	return (0);

// 		temp(argv[2], path, pipe_line, 2);
// 		close(pipe_line[1]);
// 		temp(argv[3], path, pipe_line, 3);
// 		close(pipe_line[0]);

// 		// i = 2;
// 		// while (i < argc - 1)
// 		// {
// 		// 	// two_inst(argv[i], i);
// 		// 	// fork 실행,
// 		// 	// 자식 프로세스에서 프로그램 실행
// 		// 	temp(argv[i], path, i);
// 		// 	i++;
// 		// }
// 		// 3. 결과는 마지막 파일에 출력.
// 		// pipe_output_set(pipe_line, argv[argc - 1]);
// 	}
// 	return (1);
// }