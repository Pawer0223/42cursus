/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:00:23 by taesan            #+#    #+#             */
/*   Updated: 2021/05/06 19:50:07 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

/*
	** content is int *
*/

void	ft_list_print(t_list **start)
{
	t_list *list;

	if (!*start)
		return ;
	list = *start;
	while (list->content)
	{
		ft_putnbr_fd(*(int *)list->content, 1);
		ft_putstr_fd("\n", 1);
		if (is_last(list))
			break ;
		list = list->next;
	}
}
