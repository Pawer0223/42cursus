/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:49:55 by taesan            #+#    #+#             */
/*   Updated: 2021/08/25 01:17:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_command_info(t_info *info, char *input)
{
	char	*cmd;
	char 	**temp;
	int		cmd_idx;

	temp = ft_split(info->param[0], '/');
	if (!temp)
		return (error_occur_std(SPLIT_ERR));
	cmd_idx = 0;
	while (temp[cmd_idx])
		cmd_idx++;
	info->is_builtin = check_builtin(temp[cmd_idx - 1]);
	split_free(temp);
	cmd = check_command(info->paths, info->param[0], ft_strlen(info->param[0]));
	if (cmd)
	{
		free(info->param[0]);
		info->param[0] = cmd;
	}
	return (1);
}

char	**init_path(char *envp[])
{
	char	*path;
	char	**paths;

	path = 0;
	while (*envp)
	{
		path = *envp;
		if (ft_strlen(path) > 4)
		{
			if (path[0] == 'P' && path[1] == 'A' && \
					path[2] == 'T' && path[3] == 'H')
			{
				path = *envp;
				break ;
			}
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

int		copy_envp(t_info *info, char *envp[])
{
	char	**new_envp;
	char	**temp;
	int		idx;

	temp = envp;
	idx = 0;
	while (temp[idx])
		idx++;
	new_envp = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!new_envp)
		return (0);
	info->envp = new_envp;
	info->envp_cnt = idx;
	new_envp[idx] = 0;
	idx = 0;
	while (*envp)
	{
		new_envp[idx] = ft_strdup(*envp);
		if (!new_envp[idx])
			return (0);
		idx++;
		envp++;
	}
	return (1);
}

/*
		export 명령이 수행 된 후에는, envp 를 rebuild해줌.
*/
int		set_envp(t_info *info)
{
	char	**new_envp;
	char	**temp;
	int		idx;

	// idx = 0;
	// while (temp[idx])
	// 	idx++;
	// new_envp = (char **)malloc(sizeof(char *) * (idx + 1));
	// if (!new_envp)
	// 	return (0);
	// info->envp = new_envp;
	// info->envp_cnt = idx;
	// new_envp[idx] = 0;
	// idx = 0;
	// while (*envp)
	// {
	// 	new_envp[idx] = ft_strdup(*envp);
	// 	if (!new_envp[idx])
	// 		return (0);
	// 	idx++;
	// 	envp++;
	// }
	return (1);
}

/*
 맨처음에는 envp읽어서 envp만들기.
*/
int		init_envp_file(t_info *info, char *envp[])
{
	int	fd;
	int	idx;

	fd = open(ENV_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (error_occur_std(FILE_OPEN_ERR));
	idx = 0;
	while (envp[idx])
	{
		ft_putstr_fd(envp[idx], fd);
		idx++;
		if (envp[idx])
			ft_putchar_fd('\n', fd);
	}
	info->envp_cnt = idx;
	ft_close(fd);
	return (1);
}

int		init_envp(t_info *info, char *envp[])
{
	info->paths = init_path(envp);
	if (!info->paths)
		return (0);
	if (!init_envp_file(info, envp))
		return (0);
	// info->envp = envp;
	// copy를 파일 읽어서하는 걸로 바꿔줘야 함.
	if (!copy_envp(info, envp))
	{
		clear_all_data(info);
		return (0);		
	}
	return (1);
}

