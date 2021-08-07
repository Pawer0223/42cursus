/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:06:30 by taesan            #+#    #+#             */
/*   Updated: 2021/08/08 00:20:13 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	command_to_string(t_info info)
{
	t_list *temp;

    temp = info.commands;
	while (temp)
	{
		printf("[%s]\n", temp->content);
		temp = temp->next;
	}
}

void	redirect_in_to_string(t_info info)
{
	t_list *temp;
	
    temp = info.in;
	while (temp)
	{
        t_redirect_in *data = temp->content;
		printf("left : [%d], right : [%d], limiter : [%s]\n", data->left_fd, data->right_fd, data->limiter);
		temp = temp->next;
	}
}