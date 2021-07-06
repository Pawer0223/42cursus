/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:17:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/30 19:03:09 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void		split_free(char **data)
{
	int i;

	if (!data || !*data)
		return ;
	i = 0;
	while (data[i])
	{
		if (data[i])
		{
			free(data[i]);
			data[i] = 0;
		}
		i++;
	}
	free(data);
	data = 0;
}

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
