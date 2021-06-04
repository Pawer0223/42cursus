/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/04 15:38:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacks *stacks, int front, int back)
{
	t_list_db *start;
	t_list_db *last;

	if (front <= back)
	{
		start = stacks->a;
		while (start && front > 0)
		{
			start = start->next;
			front--;
			rotate(stacks, A, NO_REVERSE);
		}
	}
	else
	{
		last = ft_lstlast(stacks->a);
		while (last && back > 0)
		{
			last = last->prev;
			back--;
			rotate(stacks, A, 1);
		}
	}
}

int			get_start_seq(t_stacks *stacks, int pivot, int is_back)
{
	t_list_db	*temp;
	int			seq;

	temp = stacks->a;
	if (is_back)
		temp = ft_lstlast(temp);
	seq = 0;
	while (temp && temp->value > pivot)
	{
		temp = (is_back) ? temp->prev : temp->next;
		seq++;
	}	
	return (seq);
}
/*
	**	stacks->a ==> value > pivot 
	**	stacks->b ==> value <= pivot
*/
void		partition(t_stacks *stacks, int pivot)
{
	int			front;
	int			back;
	
	while (stacks->a)
	{
		front = get_start_seq(stacks, pivot, 0);
		back = get_start_seq(stacks, pivot, 1);
		if (front == stacks->a_size && back == stacks->a_size)
			break;
		back++;
		rotate_stack(stacks, front, back);
		push(stacks, B);
	}
}
/*
	**	size 165 more than, 65range plus 1 section
*/
void	quick_sort(t_stacks * stacks)
{
	int stack_size;
	int section_size;
	int end_idx;

	stack_size = stacks->a_size;
	if (stack_size <= 10)
		section_size = stack_size / 3;
	else if (stack_size > 10 && stack_size <= 80)
		section_size = stack_size / 4;
	else if (stack_size > 80 && stack_size <= 165)
		section_size = stack_size / 5;
	else
		section_size = 5 + ((stack_size - 100) % SECTION_STD);
	end_idx = section_size - 1;
	while (1)
	{
		if (end_idx >= stack_size)
		{
			partition(stacks, *stacks->sorted[stack_size - 1]);
			return ;
		}
		partition(stacks, *stacks->sorted[end_idx]);
		end_idx += section_size;
	}
}
