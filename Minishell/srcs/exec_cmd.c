/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:45:56 by taesan            #+#    #+#             */
/*   Updated: 2021/08/13 16:42:46 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	pipex는 input데이터가 파일 또는 here_doc에들어왔음. 즉, 파일을 무조건 받음.

	pipex는 out또한 반드시 존재했음.

	그래서 dup2대상이 항상 in, out동일하게 처리해야 했음. 마지막에만 파일로 변경.
*/

int	exec_dup2(int pipe[2], int flags)
{
	if ((flags & STDIN_PIPE) && dup2(pipe[READ_FD_IDX], STDIN_FILENO) < 0)
		return (error_occur_perror(DUP2_ERR));
	if ((flags & STDOUT_PIPE) && dup2(pipe[WRITE_FD_IDX], STDOUT_FILENO) < 0)
		return (error_occur_perror(DUP2_ERR));

	// redirection_list를 돌면서, 입출력 처리.
	return (1);
}

void	child_process(t_info *info, int pipe[2], int flags)
{
	int		dup_r;
	char	*command;

	dup_r = 1;
	if (pipe)
	{
		dup_r = exec_dup2(pipe, flags);
		close(pipe[0]);
		close(pipe[1]);
	}
	if (dup_r)
	{
		command = info->param[0];
		if (execve(command, info->param, info->envp) == -1)
		{
			// 여기에 걸리면, && 또는 ||를 확인하여, 다음프로세스를 진행할지 여부를 결정한다.
			perror("execve");
			exit(0);
		}
	}
}

void	parent_process(t_info *info, int pipe[2], int flags)
{
	int	status;
	int	r;

	r = wait(&status);
	while (r == -1 && errno == EINTR)
		r = wait(&status);
	if (r == -1)
		perror(WAIT_ERR);
	split_free(info->param);
	info->param = 0;
	if (!pipe)
		pipe = info->pipe_out;
	if (flags & STDIN_PIPE)
		close(pipe[READ_FD_IDX]);
	if (flags & STDOUT_PIPE)
		close(pipe[WRITE_FD_IDX]);
}

void	exec_command(t_info *info, int pipe[2], int flags)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid > 0)
		parent_process(info, pipe, flags);
	else if (cpid < 0)
		perror("fork");
	else
		child_process(info, pipe, flags);
}

void	exec_call(t_info *info, int seq)
{
	//1 개의 명령어만 존재하는 경우, dup를 할필요가 없음 but out파이프의 write fd는 닫아주자.
	// 얘 플래그는 close를 위해서.
	if (info->command_cnt == 0 && seq == 0)
		exec_command(info, 0, STDIN_PIPE | STDOUT_PIPE);
	// 아래의 경우는 모두 파이프를 사용함으로, in out을 모두 close해도 됨.
	
	// 다중 명령어에서 첫번째 명령어인 경우. => 표준 출력을 파이프로. connect pipe사용
	else if (info->command_cnt > 0 && seq == 0)
		exec_command(info, info->connect_pipe, STDOUT_PIPE);
	// 다중 명령어에서 마지막 명령어인 경우. => 표준 입력을 파이프로, out pipe사용
	else if (info->command_cnt == 0 && seq > 0)
		exec_command(info, info->pipe_out, STDIN_PIPE);
	// 다중 명령어의 중간 명령어들. in, out이 모두 파이프로 연결되어야 하는 경우. connect pipe사용
	else
		exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE);
}
