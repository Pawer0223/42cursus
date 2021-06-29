/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/29 17:42:35 by taesan           ###   ########.fr       */
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
	if (info->param)
		split_free(info->param);
	return (0);
}

char	**get_cmd_info(const char *cmd, char **paths)
{
	char	**cmd_info;
	char	*command;

	if (!(cmd_info = ft_split(cmd, ' ')))
	{
		split_free(paths);
		error_occur_std(SPLIT_ERR);
		return (0);
	}
	if (!(command = check_command(paths, cmd_info[0], ft_strlen(cmd_info[0]))))
	{
		split_free(paths);
		split_free(cmd_info);
		error_occur_std(COMMAND_NOT_EXIST);
		return (0);
	}
	free(cmd_info[0]);
	cmd_info[0] = 0;
	cmd_info[0] = command;
	return (cmd_info);
}

/*
	[ ]에 있는 데이터를 읽어 [ ]로 보냄.
	시작: in -> out
	두번째: out -> in
*/
int		start_multi(int argc, const char *argv[], char *envp[], t_pipe *info)
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
		if (i > 2)
		{
			info->pipe_in[0] = info->pipe_out[0];
			if (pipe(info->pipe_out) == -1)
				return (0);
		}
		info->connect_pipe[0] = info->pipe_in[0];
		info->connect_pipe[1] = info->pipe_out[1];
		if (!(info->param = get_cmd_info(argv[i], paths)))
			return (0);
		exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
		i++;
	}
	if (!(info->param = get_cmd_info(argv[i], paths)))
		return (0);
	exec_command(info, info->pipe_out, STDIN_PIPE | STDOUT_PIPE, 1);
	split_free(info->param);
	split_free(paths);
	return (1);
}


/*
	** file1, cmd1, cmd2, file2
	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt

	** multiple...
	ex) ./pipex ls.txt "grep zip" "grep u" "wc -l" result.txt
*/
int		main(int argc, const char *argv[], char *envp[])
{
	t_pipe	info;

	if (argc < 5)
		return (error_occur_std(PARAM_ERR));
	else
	{
		if (!start_multi(argc, argv, envp, &info))
			clear_info(&info);
	}
	return (1);
}
