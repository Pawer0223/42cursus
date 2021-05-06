/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:17:30 by taesan            #+#    #+#             */
/*   Updated: 2021/05/06 18:03:15 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		is_last(t_list *list)
{
	if (!list)
		return (0);
	if (list->is_last == Y)
		return (1);
	return (0);
}

int		is_first(t_list *list)
{
	if (!list)
		return (0);
	if (list->is_first == Y)
		return (1);
	return (0);
}

int		is_null(t_list **start)
{
	if (!start || !*start)
		return (1);
	return (0);
}
