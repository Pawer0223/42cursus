/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/05 13:59:30 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		start_here_doc(int argc, const char *argv[], char *envp[], t_pipe *info)
{
	char	**paths;
	int		status;

	if (!init_pipe_bonus(argv[2], argv[argc - 1], envp, info))
		return (0);
	if (!(paths = set_path(envp)))
		return (0);
	if (!set_connect_pipe(info, 2))
		return (0);
	if (!exec_call(info, argv[3], paths, 0))
		return (0);
	if (!exec_call(info, argv[4], paths, 1))
		return (0);
	wait(&status);
	split_free(paths);
	return (1);
}

int		main(int argc, const char *argv[], char *envp[])
{
	t_pipe	info;
	int		r;

	if (argc < 5)
		return (error_occur_std(PARAM_ERR));
	else
	{
		if (ft_strcmp(argv[1], HERE_DOC) == 0)
		{
			if (argc != 6)
				return (error_occur_std(PARAM_ERR_BONUS));
			r = start_here_doc(argc, argv, envp, &info);
		}
		else
			r = start(argc, argv, envp, &info);
		if (!r && unlink(argv[argc - 1]) == -1)
			return (error_occur_std(UNLINK_ERR));
		clear_info(&info);
	}
	return (r);
}
