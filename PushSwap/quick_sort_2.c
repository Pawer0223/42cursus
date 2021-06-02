/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/02 18:06:23 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorting_push(t_stacks *stacks, char name, int push_d)
{
	int			idx;
	int			size;
	int			mid;
	t_list_db	*stack;
	char		push_stack;

	push_stack = (name == A) ? B : A;
	stack = (name == A) ? stacks->b : stacks->a;
	size = (name == A) ? stacks->b_size : stacks->a_size;
	mid = (size / 2);

	idx = 0;
	while (stack)
	{
		if (name == A && push_d > stack->value)
			break ;
		if (name == B && push_d <= stack->value)
			break ;
		stack = stack->next;
		idx++;
	}
	//printf("insert idx : %d\n", idx);
	if (idx == 1)
	{
		//printf("#1\n");
		push(stacks, push_stack);
		swap(stacks, push_stack);
	}
	else if (idx == size)
	{
		//printf("#2\n");
		push(stacks, push_stack);
		rotate(stacks, push_stack, NO_REVERSE);
	}
	else if (idx <= mid)
	{
		//printf("#3\n");
		loop_rotate(stacks, push_stack, idx, NO_REVERSE);
		push(stacks, push_stack);
		loop_rotate(stacks, push_stack, idx, 1);
	}
	else if (idx > mid)
	{
		//printf("#4\n");
		idx = size - idx;
		loop_rotate(stacks, push_stack, idx, 1);
		push(stacks, push_stack);
		loop_rotate(stacks, push_stack, idx + 1, NO_REVERSE);
	}
}

int			send_a_to_b_desc(t_stacks *stacks, int pivot)
{
	t_list_db	*last;
	t_list_db	*start;
	int			data;
	int			front;
	int			back;
	//printf("pivot : %d, size : %d\n", pivot, size);

	// size의 데이터를 1 ~ 4 과정을 통해서 보냄.
	// 1. 앞에서 pivot보다 작은 값을 찾을때까지
	while (stacks->a)
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
		// 4 - 1. push하기전에 확인. -> 정렬이 되어있는지
		if (check_sorted(stacks->a, stacks->a_size))
			return (1);
		data = stacks->a->value;
		// 4. push하기전에 확인. -> 큰 값이 가장 상단에 유지될 수 있도록 (desc)
		if (!stacks->b || data > stacks->b->value)
			push(stacks, B);
		else
		{
			//printf("push data : %d, b to : %d\n", data, stacks->b->value);
			sorting_push(stacks, A, data);
		}
		
		// 5. 정렬이 되어있는지 확인 후. 정렬이 되어있다면 더이상 push할 필요가 없음.
		if (check_sorted(stacks->a, stacks->a_size))
			return (1);
		//print_stack(stacks);
	}
	return (0);
}
/*
	피벗 기준으로 작은수를 B로 큰수를 A로 저장.

	stacks->a ==> value >= pivot 
	stacks->b ==> value < pivot
*/
int		partition(t_stacks *stacks, int mid)
{
	int	pivot;
	
	pivot = *stacks->sorted[mid];

	//printf("--------- idx_l : %d ~ idx_r : %d --> sorted[%d] : %d ---------\n", idx_l, idx_r, mid, pivot);
	// pivot을 포함하지않는 n개의 데이터
	if (stacks->a_size <= 3)
		no_push_sort(stacks);
	if (send_a_to_b_desc(stacks, pivot))
	{
		while (stacks->b)
		{
			// 여기서는, 정렬되어있기 때문에 한방에 넣어도 될듯.
			// 되감기가 필요 없을듯.
			sorting_push(stacks, B, stacks->b->value);
			if (!stacks->b)
				break ;
		}
		//printf("### 2 ###\n");
		//print_stack(stacks);
		return (1);
	}
	//print_stack(stacks);
	return (0);
}

void		quick_sort(t_stacks *stacks, int idx_l, int idx_r)
{
	int mid;

	// 균등 분할이 이뤄날 수 있도록.
	if (idx_l < idx_r)
	{
		mid = (idx_l + idx_r) / 2;
		if (!partition(stacks, mid))
		{
			quick_sort(stacks, idx_l, mid);
			quick_sort(stacks, mid + 1, idx_r);
		}
		// if (!partition(stacks, idx_l, idx_r, mid))
		// {
		// 	// quick_sort(stacks, idx_l, mid);
		// 	quick_sort(stacks, mid + 1, idx_r);
		// }
	}
}

void	exec_sort(t_stacks *stacks)
{
	quick_sort(stacks, 0, stacks->a_size - 1);

	//printf("--- sorting end stack .. ---");
	//print_stack(stacks);

	while (stacks->b)
		push(stacks, A);
	//print_stack(stacks);
}
