/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:43:52 by taesan            #+#    #+#             */
/*   Updated: 2021/06/04 21:14:35 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_list_db *stack, int data[3])
{
	data[0] = stack->value;
	data[1] = stack->next->value;
	data[2] = stack->next->next->value;
}

void	three_sort(t_stacks *stacks)
{
	int	data[3];
	int min;

	set_data(stacks->a, data);
	min = (data[0] < data[1]) ? data[0] : data[1];
	min = (min < data[2]) ? min : data[2];
	while (data[0] != min || data[1] > data[2])
	{
		if (data[0] > data[1] && data[0] > data[2])
			rotate(stacks, A, NO_REVERSE);
		else if (data[1] > data[0] && data[1] > data[2])
			rotate(stacks, A, 1);
		else if (data[0] > data[1])
			swap(stacks, A);
		set_data(stacks->a, data);
	}
}

/*
	** min_idx = 1 is using five_sort
*/
void	four_sort(t_stacks *stacks, int min_idx)
{
	int			idx;
	int			min;
	t_list_db	*stack;

	idx = 0;
	min = *stacks->sorted[min_idx];
	stack = stacks->a;
	while (stack)
	{
		if (stack->value == min)
			break ;
		stack = stack->next;
		idx++;
	}
	if (idx == 1)
		swap(stacks, A);
	else if (idx == 2)
		loop_rotate(stacks, A, 2, 1);
	else if (idx == 3)
		rotate(stacks, A, 1);
	push(stacks, B);
	three_sort(stacks);
	push(stacks, A);
}

void	five_sort(t_stacks *stacks)
{
	int idx;
	int min;
	t_list_db *stack;

	idx = 0;
	min = *stacks->sorted[0];
	stack = stacks->a;
	while (stack)
	{
		if (stack->value == min)
			break;
		stack = stack->next;
		idx++;
	}
	if (idx <= 2)
		loop_rotate(stacks, A, idx, NO_REVERSE);
	else
		loop_rotate(stacks, A, 5 - idx, 1);
	push(stacks, B);
	four_sort(stacks, 1);
	push(stacks, A);
}

void	below_five(t_stacks *stacks)
{
	if (stacks->a_size == 2)
		swap_if(stacks, A);
	else if (stacks->a_size == 3)
		three_sort(stacks);
	else if (stacks->a_size == 4)
		four_sort(stacks, 0);
	else if (stacks->a_size == 5)
		five_sort(stacks);
}
