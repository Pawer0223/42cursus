/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:19:05 by taesan            #+#    #+#             */
/*   Updated: 2021/01/02 19:12:54 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	    *ft_lstnew(void *content , t_list *curr)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	list->content = content;
	list->next = NULL;
    list->prev = curr;
	return (list);
}

void        ft_lstdelone(t_list *list)
{
    if (!list)
        return ;
    free(list->content);
    free(list);
}

void	    ft_lstclear(t_list *list)
{
    t_list *curr;
    t_list *prev;

	if (!list)
		return ;
    curr = list->prev;
    prev = curr->prev;
	while (prev)
	{
        ft_lstdelone(curr->next);
        ft_lstdelone(curr);
        curr = prev->prev;
        prev = prev->prev;
	}
}

t_list     *append_list(char *buf, t_list *list)
{
    t_list *next;

    if (!list && !(next = ft_lstnew(buf, NULL)))
        return (0);
    else if (list && !(next = ft_lstnew(buf, list)))
        return (0);
    if (!list)
        list = next;
    else
        list->next = next;
    return (next);
}
