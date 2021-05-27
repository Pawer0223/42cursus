/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_push_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:43:52 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 18:58:42 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_list *stack, int data[3])
{
	data[0] = *(int *)stack->content;
	data[1] = *(int *)stack->next->content;
	data[2] = *(int *)stack->next->next->content;
}

void	exec_no_push_sort(t_stacks *stacks)
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

void	no_push_sort(t_stacks *stacks, t_sort *info)
{
	if (*info->data_size == 2)
		swap_if(stacks, A);
	else if (*info->data_size == 3)
		exec_no_push_sort(stacks);
}
