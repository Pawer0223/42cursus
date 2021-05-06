/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:13:44 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 15:20:53 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list	*ft_lstlast(t_list **start)
{
	t_list *lst;

	lst = *start;
	while (lst)
	{
		if (!lst->next)
			return (lst);
		if (is_last(lst))
			return (lst);
		lst = lst->next;
	}
	return (0);
}
