/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:17:56 by taesan            #+#    #+#             */
/*   Updated: 2021/06/30 19:02:51 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*create_new_cmd(char *cmd, int len)
{
	char	*new_cmd;

	new_cmd = 0;
	if (!(new_cmd = (char *)malloc(sizeof(len + 1))))
		return (0);
	new_cmd[0] = '/';
	ft_strlcpy(new_cmd + 1, cmd, len + 1);
	return (new_cmd);
}

char	*check_command(char **paths, char *cmd, int len)
{
	char	*full_path;
	char	*new_cmd;
	int		i;

	full_path = 0;
	if ((new_cmd = create_new_cmd(cmd, len)))
	{
		i = 0;
		while (paths[i])
		{
			full_path = ft_strjoin(paths[i], new_cmd);
			if (!full_path || access(full_path, X_OK) == 0)
				break ;
			free(full_path);
			full_path = 0;
			i++;
		}
		free(new_cmd);
	}
	return (full_path);
}