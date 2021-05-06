/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:00:23 by taesan            #+#    #+#             */
/*   Updated: 2021/05/06 18:00:29 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	ft_list_print(t_list **start)
{
	t_list *list;

	if (!*start)
		return ;
	list = *start;
	while (list->content)
	{
		ft_putendl_fd(list->content, 1);
		if (is_last(list))
			break ;
		list = list->next;
	}
}
