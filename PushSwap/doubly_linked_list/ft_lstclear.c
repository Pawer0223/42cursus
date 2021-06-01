/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:27:14 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 17:32:29 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

void	ft_lstclear(t_list_db **lst)
{
	t_list_db *curr;
	t_list_db *next;

	if (!lst)
		return ;
	curr = lst[0];
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = 0;
}
