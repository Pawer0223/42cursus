/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 21:27:46 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorting_push(t_stacks *stacks, int push_d)
{
	int			idx;
	int			size;
	int			mid;
	t_list_db	*stack;

	stack = stacks->b;
	size = stacks->b_size;
	mid = (size / 2);

	idx = 0;
	while (stack)
	{
		if (push_d > stack->value)
			break ;
		stack = stack->next;
		idx++;
	}
	if (idx == 1)
	{
		push(stacks, B);
		swap(stacks, B);
	}
	else if (idx == size)
	{
		push(stacks, B);
		rotate(stacks, B, NO_REVERSE);
	}
	else if (size <= mid)
	{
		loop_rotate(stacks, B, idx, NO_REVERSE);
		push(stacks, B);
		loop_rotate(stacks, B, idx, 1);
	}
	else if (size > mid)
	{
		idx = size - idx;
		loop_rotate(stacks, B, idx, 1);
		push(stacks, B);
		loop_rotate(stacks, B, idx + 1, NO_REVERSE);
	}
}

void		send_a_to_b_desc(t_stacks *stacks, int pivot, int size)
{
	t_list_db	*last;
	t_list_db	*start;
	int			data;
	int			front;
	int			back;
	//printf("pivot : %d, size : %d\n", pivot, size);

	// size의 데이터를 1 ~ 4 과정을 통해서 보냄.
	// 1. 앞에서 pivot보다 작은 값을 찾을때까지
	while (stacks->a && size > 0)
	{
		start = stacks->a;
		front = 0;
		while (start && start->value >= pivot)
		{
			start = start->next;
			front++;
		}
		// 2. 뒤에서 pivot보다 작은 값을 찾을때까지
		last = ft_lstlast(stacks->a);
		back = 0;
		while (last && last->value >= pivot)
		{
			last = last->prev;
			back++;
		}
		if (front == stacks->a_size && back == stacks->a_size)
			break;
		//printf("front : %d, back : %d\n", front, back);
		back++;
		// 3. 1, 2중 더 빨리 보낼 수 있는걸 먼저 보냄.
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
		data = start->value;
		// 4. push하기전에 확인. -> 큰 값이 가장 상단에 유지될 수 있도록 (desc)
		if (!stacks->b || data > stacks->b->value)
			push(stacks, B);
		else
			sorting_push(stacks, data);
		//print_stack(stacks);
		size--;
	}
}
/*
	피벗 기준으로 작은수를 B로 큰수를 A로 저장.

	stacks->a ==> value >= pivot 
	stacks->b ==> value < pivot
*/
void		partition(t_stacks *stacks, int idx_l, int idx_r, int mid)
{
	int	pivot;
	int	size;
	
	pivot = *stacks->sorted[mid];
	size = (idx_r - idx_l + 1) / 2;

	//printf("--------- idx_l : %d ~ idx_r : %d --> sorted[%d] : %d ---------\n", idx_l, idx_r, mid, pivot);
	// pivot을 포함하지않는 n개의 데이터
	// if (stacks->a_size <= 3)
	// 	no_push_sort(stacks);
	// else
	send_a_to_b_desc(stacks, pivot, size);
	//print_stack(stacks);

}

void		quick_sort(t_stacks *stacks, int idx_l, int idx_r)
{
	int mid;

	if (idx_l < idx_r)
	{
		mid = (idx_l + idx_r) / 2;
		partition(stacks, idx_l, idx_r, mid);
		quick_sort(stacks, idx_l, mid);
		quick_sort(stacks, mid + 1, idx_r);
	}
}

void	exec_sort(t_stacks *stacks)
{
	quick_sort(stacks, 0, stacks->a_size - 1);

	while (stacks->b)
		push(stacks, A);
}
