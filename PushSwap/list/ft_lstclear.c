/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:27:14 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 18:54:12 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	ft_lstclear(t_list **start)
{
	t_list	*curr;
	t_list	*next;

	if (is_null(start))
		return ;
	curr = *start;
	while (curr)
	{
		if (curr->prev)
			ft_lstdelone(curr->prev);
		next = curr->next;
		ft_lstdelone(curr);
		curr = next;
	}
	*start = 0;
}
