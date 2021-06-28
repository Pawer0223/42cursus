/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/06/28 18:10:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*set_path(char *envp[])
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

int		init_pipe(const char *result_file, char *envp[], t_pipe *info)
{
	if (!(info->path = set_path(envp)))
		return (error_occur_std(ENV_PATH_NOT_EXIST));
	if (pipe(info->pipe_1) == -1)
		return (0);
	if (pipe(info->pipe_2) == -1)
		return (0);
	info->connect_pipe[0] = info->pipe_1[0];
	info->connect_pipe[1] = info->pipe_2[1];
	if ((info->result_fd = open(result_file, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 
									S_IRUSR | S_IWUSR)) == -1)
		return (error_occur_perror(OUTPUT_OPEN_ERR));
	info->envp = envp;
	return (1);
}