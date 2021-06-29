/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/29 20:20:54 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		clear_info(t_pipe *info)
{
	int i;

	i = 0;
	while (i < 2)
	{
		close(info->pipe_in[i]);
		close(info->pipe_out[i]);
		i++;
	}
	close(info->result_fd);
	split_free(info->param);
	return (0);
}

int		exec_call(t_pipe *info, const char *param, char **paths, int is_last)
{
	if (!set_param_info(info, param, paths))
		return (0);
	if (!is_last)
		exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
	else
		exec_command(info, info->pipe_out, STDIN_PIPE | STDOUT_PIPE, 1);	
	return (1);
}

/*
	[ ]에 있는 데이터를 읽어 [ ]로 보냄.
	시작: in -> out
	두번째: out -> in
*/
int		start(int argc, const char *argv[], char *envp[], t_pipe *info)
{
	int		i;
	char	**paths;
	int		status;

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
		r = start(argc, argv, envp, &info);
		clear_info(&info);
	}
	return (r);
}
