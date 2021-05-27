/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:55:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 17:53:11 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	a->b desc
	b->a asc
*/
int		check_order_end(char name, int value, int push_d)
{
	if (name == B && value < push_d) // b로 옮길땐 오름차순
		return (1);
	else if (name == A && value > push_d) // a로 옮길땐 내림차순
		return (1);
	return (0);
}

/*
	**	first white space possible
	**	next '-' or '+' possible, next only number
*/
int			*check_param(const char *str)
{
	int			i;
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		flag *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (!str[i])
		return (make_num(result * flag));
	return (0);
}

int			duplicate_check(t_list **list, int num)
{
	t_list *lst;

	lst = *list;
	while (lst)
	{
		if (*(int *)lst->content == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}
