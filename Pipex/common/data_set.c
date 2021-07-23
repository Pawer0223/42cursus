/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/07/02 00:06:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**set_path(char *envp[])
{
	char	*path;
	char	**paths;

	path = 0;
	while (*envp)
	{
		path = *envp;
		if (ft_strlen(path) < 4)
			continue ;
		if (path[0] == 'P' && path[1] == 'A' && \
				path[2] == 'T' && path[3] == 'H')
		{
			path = *envp;
			break ;
		}
		envp++;
	}
	if (!path)
		path = PATH;
	paths = ft_split(path + 5, ':');
	if (!paths)
		error_occur_std(SPLIT_ERR);
	return (paths);
}

int	init_pipe(const char *input, const char *output, char *envp[], t_pipe *info)
{
	int	fd;

	info->param = 0;
	info->out_file = output;
	if (pipe(info->pipe_in) == -1)
		return (error_occur_perror(PIPE_ERR));
	if (pipe(info->pipe_out) == -1)
		return (error_occur_perror(PIPE_ERR));
	info->result_fd = open(output, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, \
							S_IRUSR | S_IWUSR);
	if (info->result_fd == -1)
		return (error_occur_perror(OUTPUT_OPEN_ERR));
	info->envp = envp;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	dup2(fd, info->pipe_in[READ_FD_IDX]);
	close(fd);
	close(info->pipe_in[WRITE_FD_IDX]);
	return (1);
}

int	set_single_quote(t_pipe *info, const char *cmd, char **paths)
{
	char	**cmd_info;
	char	*command;
	char	*temp;
	int		i;
	int		len;

	cmd_info = (char **)malloc(sizeof(char *) * 3);
	if (!cmd_info)
		return (0);
	i = 1;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	temp = ft_substr(cmd, 1, i - 1);
	if (!temp)
		return (0);
	len = ft_strlen(temp);
	command = check_command(paths, temp, len);
	free(temp);
	cmd_info[0] = command;
	cmd_info[1] = ft_substr(cmd, len + 2, ft_strlen(cmd) - len - 3);
	if (!cmd_info[1])
		return (0);
	cmd_info[2] = 0;
	info->param = cmd_info;
	return (1);
}

int	set_param_info(t_pipe *info, const char *cmd, char **paths)
{
	char	**cmd_info;
	char	*command;

	if (cmd[0] == '\'')
		return (set_single_quote(info, cmd, paths));
	else
	{
		cmd_info = ft_split(cmd, ' ');
		if (!cmd_info)
		{
			split_free(paths);
			return (error_occur_std(SPLIT_ERR));
		}
		command = check_command(paths, cmd_info[0], ft_strlen(cmd_info[0]));
		if (command)
		{
			free(cmd_info[0]);
			cmd_info[0] = 0;
			cmd_info[0] = command;
		}
		info->param = cmd_info;
	}
	return (1);
}

int	set_connect_pipe(t_pipe *info, int i)
{
	if (i > 2)
	{
		info->pipe_in[0] = info->pipe_out[0];
		if (pipe(info->pipe_out) == -1)
			return (error_occur_perror(PIPE_ERR));
	}
	info->connect_pipe[0] = info->pipe_in[0];
	info->connect_pipe[1] = info->pipe_out[1];
	return (1);
}
