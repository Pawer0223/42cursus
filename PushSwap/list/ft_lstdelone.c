/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:36:57 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 17:52:20 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

/*
	** free start is idx 0
	** prev -> content
	** last->next is first free complete
*/

void	ft_lstdelone(t_list *list)
{
	if (!list->prev)
		free(list->prev);
	if (!list->content)
		free(list->content);
	list = 0;
}
