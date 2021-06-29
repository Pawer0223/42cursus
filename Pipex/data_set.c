/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/06/29 17:28:15 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	**set_path(char *envp[])
{
	char	*path;
	char	**paths;

	path = 0;
	while (*envp)
	{
		path = *envp;
		if (ft_strlen(path) < 4)
			continue;
		if (path[0] == 'P' && path[1] == 'A' && path[2] == 'T' && path[3] == 'H')
		{
			path = *envp;
			break;
		}
		envp++;
	}
	if (!path)
		path = PATH;
	if (!(paths = ft_split(path + 5, ':')))
	{
		error_occur_std(SPLIT_ERR);
		return (0);
	}
	return (paths);
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

int		init_pipe(const char *input, const char *output, char *envp[], t_pipe *info)
{		
	if (pipe(info->pipe_in) == -1)
		return (0);
	if (pipe(info->pipe_out) == -1)
		return (0);
	if ((info->result_fd = open(output, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 
									S_IRUSR | S_IWUSR)) == -1)
		return (error_occur_perror(OUTPUT_OPEN_ERR));
	info->envp = envp;
	if (!(input_pipe_fill(input, info->pipe_in)))
		return (0);
	return (1);
}
