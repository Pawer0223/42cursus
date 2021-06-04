/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:55:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/04 15:13:21 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_list_db *stack, int size)
{
	int		prev;
	int		next;

	if (size < 2)
		return (0);
	prev = stack->value;
	next = stack->next->value;
	if (prev > next)
		return (0);
	while (stack)
	{
		if (prev > next)
			return (0);
		prev = next;
		stack = stack->next;
		if (stack)
			next = stack->value;
	}
	return (1);
}

int			check_param(char *str)
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
	result *= flag;
	if (!str[i] && result >= INT_MIN && result <= INT_MAX)
		return (1);
	return (0);
}

int			duplicate_check(t_list_db *list, int num)
{
	while (list)
	{
		if (list->value == num)
			return (1);
		list = list->next;
	}
	return (0);
}
