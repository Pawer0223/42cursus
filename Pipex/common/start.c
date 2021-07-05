/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:17:06 by taesan            #+#    #+#             */
/*   Updated: 2021/07/05 20:21:30 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int		start(int argc, const char *argv[], char *envp[], t_pipe *info)
{
	int		i;
	char	**paths;

	if (!init_pipe(argv[1], argv[argc - 1], envp, info))
		return (0);
	if (!(paths = set_path(envp)))
		return (0);
	i = 2;
	while (i < argc - 2)
	{
		if (!set_connect_pipe(info, i))
			return (0);
		if (!exec_call(info, argv[i], paths, 0))
			return (0);
		i++;
	}
	if (!exec_call(info, argv[i], paths, 1))
		return (0);
	split_free(paths);
	return (1);
}