/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:45:56 by taesan            #+#    #+#             */
/*   Updated: 2021/06/28 20:26:12 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		exec_dup2(t_pipe *info, int pipe[2], int flags, int is_last)
{
	if ((flags & STDIN_PIPE) && dup2(pipe[READ_FD_IDX], STDIN_FILENO) < 0)
		return (error_occur_perror(DUP2_ERR));
	if (flags & STDOUT_PIPE)
	{
		if (is_last)
		{
			if (dup2(info->result_fd, STDOUT_FILENO) < 0)
				return (error_occur_perror(DUP2_ERR));
			close(info->result_fd);
		}
		else if (dup2(pipe[WRITE_FD_IDX], STDOUT_FILENO) < 0)
			return (error_occur_perror(DUP2_ERR));
	}
	return (1);
}

void	child_process(t_pipe *info, int pipe[2], int flags, int is_last)
{
	int		dup_r;
	char	*command;

	dup_r = exec_dup2(info, pipe, flags, is_last);
	close(pipe[0]);
	close(pipe[1]);
	if (dup_r)
	{
		command = info->param[0];
		execve(command, info->param, info->envp);
		perror("execv");
	}
}

void	parent_process(t_pipe *info, int pipe[2], int flags, int is_last)
{
	free(info->param);
	if (flags & STDIN_PIPE)
		close(pipe[READ_FD_IDX]);
	if (flags & STDOUT_PIPE)
	{
		if (is_last)
			close(info->result_fd);
		else
			close(pipe[WRITE_FD_IDX]);
	}
}

void	exec_command(t_pipe *info, int pipe[2], int flags, int is_last)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid > 0)
		parent_process(info, pipe, flags, is_last);
	else if (cpid < 0)
		perror("fork");
	else
		child_process(info, pipe, flags, is_last);
}