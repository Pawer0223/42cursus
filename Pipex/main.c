/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/28 20:26:06 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		clear_info(t_pipe *info)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (info->pipe_1[i] > 0)
			close(info->pipe_1[i]);
		if (info->pipe_2[i] > 0)
			close(info->pipe_2[i]);
		i++;
	}
	if (info->result_fd > 0)
		close(info->result_fd);
	return (0);
}

int		input_pipe_fill(const char *file, int pipe[2])
{
	int		fd;
	char	buf[BUFFER_SIZE];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	while (read(fd, buf, BUFFER_SIZE))
		write(pipe[WRITE_FD_IDX], buf, BUFFER_SIZE);
	close(pipe[WRITE_FD_IDX]);
	return (1);
}

char		**get_cmd_info(const char *cmd, char *path)
{
	char	**cmd_info;

	if (!(cmd_info = ft_split(cmd, ' ')))
	{
		error_occur_std(SPLIT_ERR);
		return (0);
	}
	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
	{
		split_free(cmd_info);
		error_occur_std(COMMAND_NOT_EXIST);
		return (0);
	}
	return (cmd_info);
}

int		start(const char *argv[], char *envp[], t_pipe *info)
{
	if (!init_pipe(argv[4], envp, info))
		return (0);
	if (!(input_pipe_fill(argv[1], info->pipe_1)))
		return (0);


	if (!(info->param = get_cmd_info(argv[3], info->path)))
		return (0);
	exec_command(info, info->pipe_2, STDIN_PIPE | STDOUT_PIPE, 1);
	
	if (!(info->param = get_cmd_info(argv[2], info->path)))
		return (0);
	exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
	return (1);
}

/*
	** file1, cmd1, cmd2, file2
	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt
*/
int		main(int argc, const char *argv[], char *envp[])
{
	t_pipe	info;

	if (argc < 5)
		return (error_occur_std(PARAM_ERR));
	else
	{
		if (!start(argv, envp, &info))
			clear_info(&info);
	}
	return (1);
}
