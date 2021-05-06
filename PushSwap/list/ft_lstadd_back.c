/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:23:49 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 18:03:30 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **start, t_list *new)
{
	t_list	*temp;
	t_list	*last;

	if (is_null(start) || !new)
		return ;
	last = ft_lstlast(start);
	temp = *start;
	last->is_last = N;
	new->is_last = Y;
	last->next = new;
	temp->prev = new;
	new->next = temp;
	new->prev = last;
}

