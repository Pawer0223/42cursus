/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:16:51 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 14:33:05 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

t_list_db	*ft_lstnew(int num)
{
	t_list_db	*list;

	if (!(list = (t_list_db *)malloc(sizeof(t_list_db))))
		return (0);
	list->value = num;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
