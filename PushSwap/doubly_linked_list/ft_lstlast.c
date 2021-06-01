/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:13:44 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 14:47:02 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

t_list_db	*ft_lstlast(t_list_db *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
