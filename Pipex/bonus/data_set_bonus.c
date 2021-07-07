/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/07/07 13:36:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex_bonus.h"

int		make_temp_file(const char *limiter)
{
	char	*buf;
	int		r;
	int		fd;

	fd = open(TEMP_FILE, O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (error_occur_perror(MAKE_TEMP_FILE));
	r = get_next_line(STDIN_FILENO, &buf);
	while (r > 0)
	{
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		r = get_next_line(STDIN_FILENO, &buf);
	}
	close(fd);
	if (!buf)
		free(buf);
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
	return (make_temp_file(limiter));
}
