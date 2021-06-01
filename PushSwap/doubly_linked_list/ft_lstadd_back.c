/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:23:49 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 17:16:06 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

void	ft_lstadd_back(t_list_db **lst, t_list_db *new)
{
	t_list_db *last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(lst[0]);
		new->next = NULL;
		new->prev = last;
		last->next = new;
	}
}
