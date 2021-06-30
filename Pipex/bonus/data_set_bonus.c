/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/06/30 19:44:09 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex_bonus.h"

int		input_pipe_fill_bonus(const char *limiter, int pipe[2])
{
	char	buf[BUFFER_SIZE];
	int		r;
	char	last;

	while ((r = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		last = buf[r - 1];
		buf[r - 1] = 0;
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		buf[r - 1] = last;
		write(pipe[WRITE_FD_IDX], buf, BUFFER_SIZE);
	}
	close(pipe[WRITE_FD_IDX]);
	if (r == -1)
		return error_occur_std(READ_ERR);
	return (1);
}

int		init_pipe_bonus(const char *limiter, const char *output, char *envp[], t_pipe *info)
{		
	info->param = 0;
	info->out_file = output;
	if (pipe(info->pipe_in) == -1)
		return (error_occur_perror(PIPE_ERR));
	if (pipe(info->pipe_out) == -1)
		return (error_occur_perror(PIPE_ERR));
	if ((info->result_fd = open(output, O_WRONLY | O_CREAT | O_APPEND, 
									S_IRUSR | S_IWUSR)) == -1)
		return (error_occur_perror(OUTPUT_OPEN_ERR));
	info->envp = envp;
	if (!(input_pipe_fill_bonus(limiter, info->pipe_in)))
		return (0);
	return (1);
}
