/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 03:36:05 by taesan            #+#    #+#             */
/*   Updated: 2021/06/04 03:36:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max_idx(t_list_db *stack)
{
	int			max;
	int			max_idx;
	int			idx;

	max = INT_MIN;
	max_idx = 0;
	idx = 0;
	while (stack)
	{
		if (stack->value >= max)
		{
			max_idx = idx;
			max = stack->value;
		}
		stack = stack->next;
		idx++;
	}
	return (max_idx);
}

/*
	** find max idx and push
*/
void	sorting_push_b_to_a(t_stacks *stacks)
{
	int	size;
	int	max_idx;

	while (stacks->b)
	{
		size = stacks->b_size;
		max_idx = get_max_idx(stacks->b);
		if (max_idx == 1)
			swap(stacks, B);
		else if (max_idx == size - 1)
			rotate(stacks, B, 1);
		else if (max_idx <= (size / 2) - 1)
			loop_rotate(stacks, B, max_idx, NO_REVERSE);
		else if (max_idx > (size / 2) - 1)
			loop_rotate(stacks, B, (size - max_idx), 1);
		push(stacks, A);
	}
}