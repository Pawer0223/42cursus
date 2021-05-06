/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:27:14 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 17:25:21 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	ft_lstclear(t_list **start)
{
	t_list *curr;
	t_list *next;

	if (!start)
		return ;
	curr = *start;
	while (curr)
	{
		next = curr->next;
		ft_lstdelone(curr);
		curr = next;
	}
	*start = 0;
}
