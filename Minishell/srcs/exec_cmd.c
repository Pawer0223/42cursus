/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:45:56 by taesan            #+#    #+#             */
/*   Updated: 2021/08/08 15:51:36 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	here_doc(char	*limiter, int fd_in)
{
	char	*buf;
	int		r;
	int		fd;

	fd = open(TEMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	r = get_next_line(fd_in, &buf);
	while (r > 0)
	{
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		r = get_next_line(fd_in, &buf);
	}
	if (buf)
		free(buf);
	close(fd);
	return (1);	
}

/*
	dup하면서 close해주는 코드 심기.
*/
int	redirection_change(t_info *info)
{
	t_list			*temp;
	t_redirect_in	*data_in;
	t_redirect_out	*data_out;

	// 중간에 dup2에 의해 표준 입, 출력이 변경된다. 백업해두고 사용
	int fd_in;
	fd_in = dup(STDIN_FILENO);

	temp = info->in;
	while (temp)
	{
		data_in = temp->content;
		if (data_in->limiter)
		{
			// free시점 맞춰야 함..
			if (!here_doc(data_in->limiter, fd_in))
				break ;// return (0);
			data_in->right_fd = open(TEMP_FILE, O_RDONLY);
			if (data_in->right_fd == -1)
				break ;// return (error_occur_perror(INPUT_OPEN_ERR));
		}
		dup2(data_in->right_fd, data_in->left_fd);
		// close(data_in->right_fd);
		temp = temp->next;
	}
	if (info->in)
		ft_lstclear(&info->in, redirect_in_free);
	close(fd_in);
	temp = info->out;
	while (temp)
	{
		data_out = temp->content;
		dup2(data_out->right_fd, data_out->left_fd);
		// close(data_out->right_fd);
		temp = temp->next;
	}
	if (info->out)
		ft_lstclear(&info->out, ft_free);
	return (1);
}

void	child_process(t_info *info)
{
	int		dup_r;
	char	*command;

	command = info->param[0];
	redirection_change(info);
	execve(command, info->param, info->envp);
	perror("execve");
	exit(0);
}

void	parent_process(t_info *info)
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
}

void	exec_command(t_info *info)
{
	pid_t	cpid;

	if (info->is_builtin)
	{
		printf("is built in\n");
	}
	else
	{
		cpid = fork();
		if (cpid > 0)
			parent_process(info);
		else if (cpid < 0)
			perror("fork");
		else
			child_process(info);
	}
}