/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:36:57 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 18:53:53 by taesan           ###   ########.fr       */
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
	if (list->content)
		free(list->content);
	list->content = 0;
	list = 0;
}
