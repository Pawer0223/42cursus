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

#include "pipex_bonus.h"

int	make_temp_file(const char *limiter)
{
	char	*buf;
	int		r;
	int		fd;

	fd = open(TEMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	r = get_next_line(STDIN_FILENO, &buf);
	while (r > 0)
	{
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		r = get_next_line(STDIN_FILENO, &buf);
	}
	if (buf)
		free(buf);
	close(fd);
	return (1);
}

int	init_pipe_bonus(const char *lim, const char *outp, char *env[], t_pipe *inf)
{		
	inf->param = 0;
	inf->out_file = outp;
	if (pipe(inf->pipe_in) == -1)
		return (error_occur_perror(PIPE_ERR));
	if (pipe(inf->pipe_out) == -1)
		return (error_occur_perror(PIPE_ERR));
	inf->result_fd = open(outp, O_WRONLY | O_CREAT | O_APPEND, \
					S_IRUSR | S_IWUSR);
	if (inf->result_fd == -1)
		return (error_occur_perror(OUTPUT_OPEN_ERR));
	inf->envp = env;
	return (make_temp_file(lim));
}
