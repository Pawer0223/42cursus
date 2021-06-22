/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:17:56 by taesan            #+#    #+#             */
/*   Updated: 2021/06/22 21:18:02 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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