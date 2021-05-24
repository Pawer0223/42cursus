/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:25:12 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 15:26:08 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*get_list(t_list **list, int idx)
{
	t_list *temp;

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
