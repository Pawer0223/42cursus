/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/22 21:55:39 by taesan           ###   ########.fr       */
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

int		fill_buf2(int fds[2])
{

	int		fd;
	char	*buf;

	char	*file = "ls.txt";
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_occur());
	buf = (char *)malloc(sizeof(char) * 10);
	while (read(fd, buf, 10))
	{
		write(fds[1], buf, 10);
	}
	return (1);
}

int first(const char *file, char **param)
{
	file = 0;
	int fds[2];         // an array that will hold two file descriptors
	pipe(fds);          // populates fds with two file descriptors
	pid_t pid = fork(); // create child process that is a clone of the parent

	char *cmd = param[0];

	if (pid == 0)
	{                                          // if pid == 0, then this is the child process
		dup2(fds[0], STDIN_FILENO);            // fds[0] (the read end of pipe) donates its data to file descriptor 0
		close(fds[0]);                         // file descriptor no longer needed in child since stdin is a copy
		close(fds[1]);                         // file descriptor unused in child
		if (execvp(cmd, param) < 0)
			exit(0); // run sort command (exit if something went wrong)
	}

	// if we reach here, we are in parent process
	close(fds[0]); // file descriptor unused in parent

	fill_buf2(fds);
	
	// send EOF so child can continue (child blocks until all input has been processed):
	close(fds[1]);
	int status;
	pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
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