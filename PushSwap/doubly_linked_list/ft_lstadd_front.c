/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:59:37 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 17:15:20 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

void	ft_lstadd_front(t_list_db **lst, t_list_db *new)
{
	t_list_db *start;

	if (!lst || !new)
		return ;
	start = *lst;
	if (!start)
	{
		*lst = new;
		return;
	}
	new->next = start;
	new->prev = NULL;
	start->prev = new;
	*lst = new;
}
