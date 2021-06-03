// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort_2.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
// /*   Updated: 2021/06/04 03:22:30 by taesan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int			check_remain_min(t_stacks *stacks)
// {
// 	int			b_top;
// 	t_list_db	*a;

// 	if (!stacks->b)
// 		return (1);
// 	b_top = stacks->b->value;
// 	a = stacks->a;
// 	while (a)
// 	{
// 		if (a->value < b_top)
// 			return (0);
// 		a = a->next;
// 	}
// 	return (1);
// }

// /*
// 	a -> b
// */
// // void		sorting_push(t_stacks *stacks, char name, int push_d)
// // {
// // 	int			idx;
// // 	int			size;
// // 	int			mid;
// // 	t_list_db	*stack;
// // 	char		push_stack;

// // 	push_stack = (name == A) ? B : A;
// // 	stack = (name == A) ? stacks->b : stacks->a;
// // 	size = (name == A) ? stacks->b_size : stacks->a_size;
// // 	mid = (size / 2);

// // 	idx = 0;
// // 	while (stack)
// // 	{
// // 		if (name == A && push_d > stack->value)
// // 			break ;
// // 		if (name == B && push_d <= stack->value)
// // 			break ;
// // 		stack = stack->next;
// // 		idx++;
// // 	}
// // 	//printf("insert idx : %d\n", idx);
// // 	if (idx == 1)
// // 	{
// // 		//printf("#1\n");
// // 		push(stacks, push_stack);
// // 		swap(stacks, push_stack);
// // 	}
// // 	else if (idx == size)
// // 	{
// // 		//printf("#2\n");
// // 		push(stacks, push_stack);
// // 		rotate(stacks, push_stack, NO_REVERSE);
// // 	}
// // 	else if (idx <= mid)
// // 	{
// // 		//printf("#3\n");
// // 		loop_rotate(stacks, push_stack, idx, NO_REVERSE);
// // 		push(stacks, push_stack);
// // 		loop_rotate(stacks, push_stack, idx, 1);
// // 	}
// // 	else if (idx > mid)
// // 	{
// // 		//printf("#4\n");
// // 		idx = size - idx;
// // 		loop_rotate(stacks, push_stack, idx, 1);
// // 		push(stacks, push_stack);
// // 		loop_rotate(stacks, push_stack, idx + 1, NO_REVERSE);
// // 	}
// // }

// void		sorting_push(t_stacks *stacks, char name)
// {
// 	int			idx;
// 	int			size;
// 	int			mid;
// 	t_list_db	*stack;
// 	char		push_stack;

// 	push_stack = (name == A) ? B : A;
// 	stack = (name == A) ? stacks->b : stacks->a;


// 	idx = 0;
// 	int		min;
// 	int		min_idx;

// 	min = INT_MAX;
// 	while (stack)
// 	{
// 		if (stack->value <= min)
// 		{
// 			min_idx = idx;
// 			min = stack->value;
// 		}
// 		stack = stack->next;
// 		idx++;
// 	}

// 	size = (name == A) ? stacks->b_size : stacks->a_size;
// 	mid = (size / 2) - 1;
// 	//printf("insert idx : %d\n", idx);
// 	if (min_idx == 1)
// 	{
// 		//printf("#1\n");
// 		swap(stacks, push_stack);
// 		push(stacks, push_stack);
// 	}
// 	else if (min_idx == size - 1)
// 	{
// 		//printf("#2\n");
// 		rotate(stacks, push_stack, 1);
// 		push(stacks, push_stack);
// 	}
// 	else if (min_idx <= mid)
// 	{
// 		//printf("#3\n");
// 		loop_rotate(stacks, push_stack, min_idx, NO_REVERSE);
// 		push(stacks, push_stack);
// 	}
// 	else if (min_idx > mid)
// 	{
// 		//printf("#4\n");
// 		idx = size - min_idx;
// 		loop_rotate(stacks, push_stack, idx, 1);
// 		push(stacks, push_stack);
// 	}
// }

// void		sorting_push_2(t_stacks *stacks)
// {
// 	int			idx;
// 	int			b_top;
// 	int			size;
// 	int			mid;
// 	t_list_db	*stack;
// 	char		push_stack;

// 	push_stack = A;
// 	size = stacks->a_size;
// 	mid = (size / 2);
// 	while (stacks->b)
// 	{
// 		idx = 0;
// 		stack = stacks->a;
// 		b_top = stacks->b->value;
// 		while (stack)
// 		{
// 			if (stack->value > b_top)
// 				break;
// 			stack = stack->next;
// 			idx++;
// 		}
// 		// b-> a 삽입할껀데, 현재값보다 먼저 큰 값을 만났을 때 멈춘다.
// 		/*
// 			1. 일단 이동시켜서 맨위로 옮겨놓고,

// 			2. 삽입을 한다.

// 			3. 다음으로 top의 값을 계속해서 넣을 수 있는지 한번 더 확인한다.
// 			  - is_possible ? 다 넣고 끝.
// 			  - is_not_possible ? 처음으로 돌아가서 반복.
// 		*/
// 		// printf("top_a : %d, top_b : %d, idx : %d\n",stack->value, b_top, idx);
// 		if (idx == 0)
// 			push(stacks, push_stack);
// 		else if (idx == 1)
// 		{
// 			// printf("#1\n");
// 			push(stacks, push_stack);
// 			swap(stacks, push_stack);
// 		}
// 		else if (idx == size)
// 		{
// 			// printf("#2\n");
// 			push(stacks, push_stack);
// 			rotate(stacks, push_stack, NO_REVERSE);
// 		}
// 		else if (idx <= mid)
// 		{
// 			// printf("#3\n");
// 			loop_rotate(stacks, push_stack, idx, NO_REVERSE);
// 			loop_rotate(stacks, push_stack, idx - 1, NO_REVERSE);
// 			int prev = stacks->a->value;
// 			//printf("prev: %d, stacks->b->value : %d\n", prev, stacks->b->value);
// 			rotate(stacks, push_stack, NO_REVERSE);
// 			while (stacks->b && stacks->b->value > prev)
// 				push(stacks, push_stack);
// 			loop_rotate(stacks, push_stack, idx, 1);
// 		}
// 		else if (idx > mid)
// 		{
// 			// printf("#4\n");
// 			idx = size - idx;
// 			loop_rotate(stacks, push_stack, idx - 1, 1);
// 			int prev = stacks->a->value;
// 			//printf("prev: %d, stacks->b->value : %d\n", prev, stacks->b->value);
// 			rotate(stacks, push_stack, 1);
// 			while (stacks->b && stacks->b->value > prev)
// 				push(stacks, push_stack);
// 			loop_rotate(stacks, push_stack, idx + 1, NO_REVERSE);
// 		}
// 	}
// }

// void		check_ordered(t_stacks *stacks)
// {
// 	t_list_db	*i;
// 	t_list_db	*j;
// 	int			seq;
// 	int			mid;
// 	int			prev;
// 	int			idx;
// 	int			idx_2;

// 	idx = 0;
// 	mid = stacks->a_size / 2;
// 	i = stacks->a;
// 	while (i)
// 	{
// 		seq = 0;
// 		j = i->next;
// 		prev = i->value;
// 		while (j && prev < j->value)
// 		{
// 			prev = j->value;
// 			j = j->next;
// 			seq++;
// 		}
// 		if (seq > mid)
// 		{
// 			// printf("idx : %d, seq : %d, mid : %d\n", idx, seq, mid);
// 			idx_2 = 0;
// 			while (idx_2 < idx)
// 			{
// 				sorting_push(stacks, A);
// 				idx_2++;
// 			}
// 			idx_2 = stacks->a_size - (seq + 1);
// 			seq = idx_2;
// 			// printf("idx_2 : %d\n", idx_2);
// 			while (idx_2 > 0)
// 			{
// 				rotate(stacks, A, 1);
// 				idx_2--;
// 			}
// 			while (seq > 0)
// 			{
// 				sorting_push(stacks, A);
// 				seq--;
// 			}
// 			sorting_push_2(stacks);
// 			return ;
// 		}
// 		i = i->next;
// 		idx++;
// 	}

// }

// int			send_a_to_b_desc(t_stacks *stacks, int pivot)
// {
// 	t_list_db	*last;
// 	t_list_db	*start;
// 	int			data;
// 	int			front;
// 	int			back;
// 	// printf("pivot : [%d]\n", pivot);
// 	// size의 데이터를 1 ~ 4 과정을 통해서 보냄.
// 	while (stacks->a)
// 	{
// 		// 1. 앞에서 pivot보다 작은 값을 찾을때까지
// 		start = stacks->a;
// 		front = 0;
// 		while (start && start->value > pivot) // 작거나 같으면 멈춰서 그 데이터 보내야 함
// 		{
// 			start = start->next;
// 			front++;
// 		}
// 		// 2. 뒤에서 pivot보다 작은 값을 찾을때까지
// 		last = ft_lstlast(stacks->a);
// 		back = 0;
// 		while (last && last->value > pivot) // 작거나 같으면 멈춰서 그 데이터 보내야 함
// 		{
// 			last = last->prev;
// 			back++;
// 		}
// 		if (front == stacks->a_size && back == stacks->a_size)
// 			break;
// 		back++;
// 		//printf("front : %d, back : %d\n", front, back);
// 		// 3. 1, 2중 더 빨리 보낼 수 있는걸 먼저 보냄.
// 		if (front <= back)
// 		{
// 			start = stacks->a;
// 			while (start && front > 0)
// 			{
// 				start = start->next;
// 				front--;
// 				rotate(stacks, A, NO_REVERSE);
// 			}
// 		}
// 		else
// 		{
// 			last = ft_lstlast(stacks->a);
// 			while (last && back > 0)
// 			{
// 				last = last->prev;
// 				back--;
// 				rotate(stacks, A, 1);
// 			}
// 		}
// 		// 4 - 1. push하기전에 확인. -> 정렬이 되어있는지
// 		// if (check_sorted(stacks->a, stacks->a_size))
// 		// 	return (1);
// 		data = stacks->a->value;
// 		// 4. push하기전에 확인. -> 큰 값이 가장 상단에 유지될 수 있도록 (desc)
// 		if (!stacks->b || data > stacks->b->value)
// 			push(stacks, B);
// 		else
// 		{
// 			// printf("push data : %d, top of b  : %d\n", data, stacks->b->value);
// 			sorting_push(stacks, A);
// 		}
// 		// 5. 정렬이 되어있는지 확인 후. 정렬이 되어있다면 더이상 push할 필요가 없음.
// 		// if (check_sorted(stacks->a, stacks->a_size))
// 		// 	return (1);
// 		// print_stack(stacks);
// 	}
// 	return (0);
// }
// /*
// 	피벗 기준으로 작은수를 B로 큰수를 A로 저장.

// 	stacks->a ==> value > pivot 
// 	stacks->b ==> value <= pivot
// */
// int		partition(t_stacks *stacks, int mid)
// {
// 	int	pivot;
	
// 	pivot = *stacks->sorted[mid];

// 	// 0 1 2 3      mid = 2
// 	// 0 1 2 3 4    mid = 2

// 	// pivot을 포함하지않는 n개의 데이터
// 	if (stacks->a_size <= 3)
// 		no_push_sort(stacks);
// 	// if (send_a_to_b_desc(stacks, pivot))
// 	// {
// 	// 	// while (stacks->b)
// 	// 	// {
// 	// 	// 	// 여기서는, 정렬되어있기 때문에 한방에 넣어도 될듯.
// 	// 	// 	// 되감기가 필요 없을듯.
// 	// 	// 	sorting_push(stacks, B, stacks->b->value);
// 	// 	// 	if (!stacks->b)
// 	// 	// 		break ;
// 	// 	// }
// 	// 	sorting_push_2(stacks);
// 	// 	//printf("### 2 ###\n");
// 	// 	//print_stack(stacks);
// 	// 	return (1);
// 	// }
// 	send_a_to_b_desc(stacks, pivot);
// 	//print_stack(stacks);
// 	return (0);
// }

// void		quick_sort(t_stacks *stacks, int idx_l, int idx_r)
// {
// 	int mid;

// 	/*
// 		1. 반씩 최소단위까지 쪼갬
// 		  -> 0 ~ 250
// 		  -> 0 ~ 125 , 126 ~ 249
// 		  -> 0 ~ 63  , 64 ~ 124
// 		  -> 
// 	*/
// 	if (idx_l < idx_r)
// 	{
// 		mid = (idx_l + idx_r) / 2;
// 		// printf("--------- idx_l : %d ~ idx_r : %d --> sorted[%d] : %d ---------\n", idx_l, idx_r, mid, *stacks->sorted[mid]);
// 		if (!partition(stacks, mid))
// 			quick_sort(stacks, idx_l, mid);
// 	}
// }

// void	exec_sort(t_stacks *stacks)
// {
// 	check_ordered(stacks);
// 	quick_sort(stacks, 0, stacks->a_size - 1);

// 	// printf("--- sorting end stack .. ---\n");
// 	//print_stack(stacks);
// 	while (stacks->b)
// 	{
// 		t_list_db 	*temp;
// 		int			max;
// 		int			max_idx;
// 		int			idx;
// 		int			size;
// 		int			mid;

// 		max = INT_MIN;
// 		max_idx = 0;
// 		temp = stacks->b;
// 		idx = 0;
// 		// print_stack(stacks);
// 		while (temp)
// 		{
// 			if (temp->value >= max)
// 			{
// 				max_idx = idx;
// 				max = temp->value;
// 			}
// 			temp = temp->next;
// 			idx++;
// 		}
// 		size = stacks->b_size;
// 		mid = size / 2 - 1;
// 		// printf("max_idx : %d, size : %d, mid : %d\n", max_idx, size, mid);
// 		if (max_idx == 0)
// 			push(stacks, A);
// 		else if (max_idx == 1)
// 		{
// 			// printf("#1\n");
// 			swap(stacks, B);
// 			push(stacks, A);
// 		}
// 		else if (max_idx == size - 1)
// 		{
// 			// printf("#2\n");
// 			rotate(stacks, B, 1);
// 			push(stacks, A);
// 		}
// 		else if (max_idx <= mid)
// 		{
// 			// printf("#3\n");
// 			loop_rotate(stacks, B, max_idx, NO_REVERSE);
// 			push(stacks, A);
// 		}
// 		else if (max_idx > mid)
// 		{
// 			// printf("#4\n");
// 			idx = size - max_idx;
// 			loop_rotate(stacks, B, idx, 1);
// 			push(stacks, A);
// 		}
// 	}
// 	// print_stack(stacks);
// }
