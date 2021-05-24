/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:13:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 19:40:43 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disconnect_content(void *content)
{
	content = 0;
	return ;
}

void	delete_content(void *content)
{
	free(content);
}

int		error_occur()
{
	ft_putendl_fd(ERROR, 1);
	return (0);
}
