#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pipex.h"


#define STDIN_PIPE 0x1
#define STDOUT_PIPE 0x2

void			split_free(char **data)
{
	int i;

	if (!data || !*data)
		return ;
	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

char			*check_command(const char *path, char *cmd, int len)
{
	char	**paths;
	char	*full_path;
	char	*new_cmd;
	int		i;

	if (!(paths = ft_split(path, ':')))
		return (0);
	if (!(new_cmd = (char *)malloc(sizeof(len + 1))))
		return (0);
	new_cmd[0] = '/';
	ft_strlcpy(new_cmd + 1, cmd, len + 1);
	i = 0;
	while (paths[i])
	{
		if (!(full_path = ft_strjoin(paths[i], new_cmd)))
		{
			split_free(paths);
			return (0);
		}
		if (access(full_path, X_OK) == 0)
			return (full_path);
		i++;
	}
	split_free(paths);
	return (0);
}

char		*set_path(char *envp[])
{
	char *path;

	while (*envp)
	{
		path = *envp;
		if (ft_strlen(path) < 4)
			continue;

		if (path[0] == 'P' && path[1] == 'A' && path[2] == 'T' && path[3] == 'H')
		{
			path = *envp;
			return (path);
		}
		envp++;
	}
	return (0);
}

// void two_inst()
// {
// 	int pipefd1[2];
// 	pipe(pipefd1);
// 	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
// 	close(pipefd1[1]);
// 	exec_command("/usr/bin/wc", pipefd1, STDIN_PIPE);
// 	close(pipefd1[0]);
// 	int wstatus;
// 	while (wait(&wstatus) > 0);
// }

int		temp(const char *cmd, char *path)
{
	char	**cmd_info;

	if (!(cmd_info = ft_split(cmd, ' ')))
	{
		printf("cmd split error\n");
		return (0);
	}
	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
	{		//free cmd_info
		return (0);
	}
	printf("cmd : %s\n", cmd_info[0]);
	// free cmd_info
	return (0);
}

void	pipe_input_set(int pipe_line[2], const char *file)
{
	pipe_line = 0;
	file = 0;
	// 파이프 열고
}

void	pipe_output_set(int pipe_line[2], const char *file)
{
	pipe_line = 0;
	file = 0;
	// 파이프 닫고
}

/*
	** file1, cmd1, cmd2, file2
	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt
*/
int		main(int argc, const char *argv[], char *envp[])
{
	char	*path;
	int		pipe_line[2];
	int		i;

	if (argc < 5)
		printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
	else
	{
		if (!(path = set_path(envp)))
		{
			printf("path is not exist\n");
			return (0);
		}
		// 1. 파일 읽어서 pipe의 in으로 설정해주기.
		pipe(pipe_line);
		pipe_input_set(pipe_line, argv[1]);
		// 2. cmd파싱 -> 자식프로세스 실행 이어서 계속
		i = 2;
		while (i < argc - 1)
		{
			temp(argv[i++], path);
		}
		// 3. 결과는 마지막 파일에 출력.
		pipe_output_set(pipe_line, argv[argc - 1]);
	}
	return (1);
}