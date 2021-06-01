/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:03:20 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 17:30:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

t_list_db		*pop(t_list_db **list)
{
	t_list_db *start;

	start = *list;
	if (!start)
		return (0);
	*list = start->next;
	if (*list)
		(*list)->prev = NULL;
	start->next = NULL;
	return (start);
}
