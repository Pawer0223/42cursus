/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/07 13:36:51 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		start_here_doc(int argc, const char *argv[], char *envp[], t_pipe *info)
{
	char	**paths;
	int		fd;

	if (!init_pipe_bonus(argv[2], argv[argc - 1], envp, info))
		return (0);
	fd = open(TEMP_FILE, O_RDONLY);
	if (fd == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	dup2(fd, info->pipe_in[READ_FD_IDX]);
	close(fd);
	close(info->pipe_in[WRITE_FD_IDX]);
	if (!(paths = set_path(envp)))
		return (0);
	if (!set_connect_pipe(info, 2))
		return (0);
	if (!exec_call(info, argv[3], paths, 0))
		return (0);
	if (!exec_call(info, argv[4], paths, 1))
		return (0);
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
			if (r && unlink(TEMP_FILE) == -1)
				return (error_occur_std(UNLINK_ERR));
		}
		else
			r = start(argc, argv, envp, &info);
		if (!r && unlink(argv[argc - 1]) == -1)
			return (error_occur_std(UNLINK_ERR));
		clear_info(&info);
	}
	return (r);
}
