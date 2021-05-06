/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:59:37 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 15:15:19 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	ft_lstadd_front(t_list **start, t_list *new)
{
	t_list	*temp;
	t_list	*last;

	if (!start || !new)
		return ;
	last = ft_lstlast(start);
	temp = *start;
	temp->is_first = N;
	new->is_first = Y;
	temp->prev = new;
	new->next = temp;
	new->prev = last;
	*start = new;
}
