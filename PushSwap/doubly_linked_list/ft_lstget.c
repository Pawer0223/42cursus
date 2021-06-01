/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:25:12 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 14:47:39 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

t_list_db	*get_list(t_list_db **list, int idx)
{
	t_list_db *temp;

	if (!list || !*list)
		return (0);
	temp = *list;
	while (idx > 0)
	{
		temp = temp->next;
		idx--;
	}
	return (temp);
}
