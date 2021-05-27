/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:11:26 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 15:44:41 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_rotate(t_stacks *stacks, char name, int cnt, int is_reverse)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		rotate(stacks, name, is_reverse);
		i++;
	}
}

int		get_prev_idx(int size)
{
	return (size - 2);
}

void	exec_rotate(t_list **stack, int last_prev)
{
	t_list	*start;
	t_list	*last;
	t_list	*prev;

	if (!stack || !*stack)
		return ;
	start = *stack;
	last = ft_lstlast(start);
	if (last_prev != NO_REVERSE)
	{
		prev = get_list(stack, last_prev);
		prev->next = 0;
		last->next = start;
		*stack = last;
	}
	else
	{
		*stack = start->next;
		start->next = 0;
		last->next = start;
	}
}

void	rotate(t_stacks *stacks, char name, int is_reverse)
{
	if (is_reverse != NO_REVERSE)
		is_reverse = get_prev_idx(stacks->a_size);
	if ((name == A || name == ALL) && stacks->a_size > 1)
		exec_rotate(&stacks->a, is_reverse);
	if (is_reverse != NO_REVERSE)
		is_reverse = get_prev_idx(stacks->b_size);
	if ((name == B || name == ALL) && stacks->b_size > 1)
		exec_rotate(&stacks->b, is_reverse);
	if (is_reverse == NO_REVERSE)
		print_inst(ROTATE, name);
	else
		print_inst(ROTATE_R, name);
}
