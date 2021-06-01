/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:13:58 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 15:17:52 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disconnect_content(void *content)
{
	content = 0;
	return ;
}

int		error_occur()
{
	ft_putendl_fd(ERROR, 1);
	return (0);
}
