/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:02:44 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 17:56:38 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

int		ft_lstsize(t_list **start)
{
	t_list	*lst;
	int		cnt;

	lst = *start;
	cnt = 0;
	while (lst)
	{
		cnt++;
		if (is_last(lst))
			return (cnt);
		lst = lst->next;
	}
	return (cnt);
}
