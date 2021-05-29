/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:55:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/29 15:29:34 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	edge_check(t_stacks *stacks)
// {
// 	int 	start;
// 	int 	last;
// 	t_list	*temp;

// 	if (stacks->a_size < 2)
// 		return ;
// 	temp = stacks->a;
// 	start = *(int *)temp->content;
// 	last = *(int *)ft_lstlast(temp)->content;
// 	if (start == stacks->max)
// 		rotate(stacks, A, NO_REVERSE);
// 	else if (last == stacks->min)
// 		rotate(stacks, A, 1);
// }

int		check_sorted(t_list *stack, int size)
{
	int		prev;
	int		next;

	if (size < 2)
		return (0);
	prev = *(int *)stack->content;
	next = *(int *)stack->next->content;
	if (prev > next)
		return (0);
	while (stack)
	{
		if (prev > next)
			return (0);
		prev = next;
		stack = stack->next;
		if (stack)
			next = *(int *)stack->content;
	}
	return (1);
}
/*
	a->b desc
	b->a asc
*/
int		check_order_end(char name, int value, int push_d)
{
	if (name == B && value < push_d)
		return (1);
	else if (name == A && value > push_d)
		return (1);
	return (0);
}
/*
	**	first white space possible
	**	next '-' or '+' possible, next only number
*/
int			*check_param(char *str)
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
