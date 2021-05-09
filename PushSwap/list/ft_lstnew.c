/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:16:51 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 19:46:23 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

/*
	**	start null is mean first. => set Y
	**	needed , caller function set start = 0
*/

t_list	*ft_lstnew(t_list **start, void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	list->content = content;
	if (!*start)
	{
		list->is_first = Y;
		list->is_last = Y;
	}
	list->next = 0;
	list->prev = 0;
	return (list);
}