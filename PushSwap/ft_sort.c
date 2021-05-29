// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_sort.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
// /*   Updated: 2021/05/29 15:35:03 by taesan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int		get_insert_idx(t_list *b, int push_d)
// {
// 	int		idx;
// 	int		value;

// 	idx = 0;
// 	while (b)
// 	{
// 		value = *(int *)b->content;
// 		if (value < push_d)
// 			return (idx);
// 		b = b->next;
// 		idx++;
// 	}
// 	return (idx);
// }

// void	sorting_push(int idx, t_stacks *stacks)
// {
// 	int	cnt;
// 	int	size;

// 	size = stacks->b_size;
// 	if (idx <= 1 || idx == size)
// 		push(stacks, B);
// 	if (idx == 1)
// 		swap(stacks, B);
// 	else if (idx == size && size > 1)
// 		rotate(stacks, B, NO_REVERSE);
// 	else if (idx > (size / 2))
// 	{
// 		cnt = size - idx;
// 		loop_rotate(stacks, B, cnt, 1);
// 		push(stacks, B);
// 		loop_rotate(stacks, B, cnt + 1, NO_REVERSE);
// 	}
// 	else if (idx <= (size / 2) && idx > 1)
// 	{
// 		loop_rotate(stacks, B, idx, NO_REVERSE);
// 		push(stacks, B);
// 		loop_rotate(stacks, B, idx, 1);
// 	}
// }

// int		get_pivot(t_stacks *stacks)
// {
// 	int		mid;
// 	int		i;
// 	int		pivot;

// 	mid = stacks->a_size / 2;
// 	if (!(sorted = merge_sort(stacks->a, 0, stacks->a_size - 1)))
// 		exit(EXIT_FAILURE);
// 	i = 0;
// 	while (i <= mid)
// 	{
// 		pivot = *(int *)sorted->content;
// 		sorted = sorted->next;
// 		i++;
// 	}
// 	stacks = 0;
// 	return (1);
// }
// /*
// 	A = 피벗보다 작은 값의 집합.
// 	B = 피벗보다 큰 값의 집합이 된다.

// 	A에서 피벗보다 작은 값을 만나면 ra를 수행하게 된다.
// 	 ra가 수행되면서 정렬할 수 있는 방법이 있을까?
// 	 오름차순 정렬 .. swap하지 않는 이상 순서는 절대 바뀌지않는다. (맨뒤, 맨 앞에 있을때 빼곤)
// 	 마지막 원소를 기록하고 있다가, ra하기전에 마지막 값이 더 크다면? rra로 올리고, swap하고 두번을 ra, ra해준다.
// 	 혹은, pb -> ra -> pa -> ra를해도 된다.
// */
// int		ft_sort(t_stacks *stacks, int size)
// {
// 	// pivot값을 찾는다.
// 	int	pivot;
// 	int	i;
// 	int	data;
// 	int	last;
// 	int	insert_idx;

// 	if (size <= 3)
// 	{
// 		// a에서 끝내기.
// 	}
	
// 	// 5 1 2 3 4 일 때
// 	// 3기준으로,
// 	// 1 2를 b로
// 	// 3 4 5 
// 	pivot = get_pivot(stacks);
// 	printf("\npivot : %d, size : %d\n", pivot, size);
// 	// pivot이하의 값을 B로 내림차순하며 보낸다.
// 	i = 0;
// 	last = *(int *)ft_lstlast(stacks->a)->content;
// 	while (stacks->a && i < size)
// 	{
// 		data = *(int *)stacks->a->content;
// 		printf("pivot [%d] ---> data : %d\n", pivot, data);
// 		if (data <= pivot)
// 		{
// 			if (stacks->b && data < peek(stacks->b))
// 			{
// 				insert_idx = get_insert_idx(stacks->b, peek(stacks->a));
// 				sorting_push(insert_idx, stacks);
// 			}
// 			else
// 				push(stacks, B);
// 		}
// 		// stack A에 오름차순해서 저장하고 있는다.
// 		else
// 		{
// 			// 마지막 값이 더 작을 때 위로올리면, 3 . . . . 2 일 때 => . . . 2 3 이렇게 됨.
// 			// 따라서 마지막 값이 더 크다면 ? 2 . . . 3일때 => 3 2 . . . 해서 swap하고 2 3 . . . 만들어서 두개를 밑으로 보내주기 . . . 2 3
// 			if (last > data)
// 			{
// 				// 데이터가 3개이하 일 때 따로 처리
// 				rotate(stacks, A, 1);
// 				swap(stacks, A);
// 				rotate(stacks, A, NO_REVERSE);
// 			}
// 			rotate(stacks, A, NO_REVERSE);
// 		}
// 		if (stacks->b_size == 0 && check_sorted(stacks->a, stacks->a_size))
// 			break ;
// 		print_stack(stacks);
// 		i++;
// 	}
// 	// 재귀 해야 함..
// 	// ft_sort(stacks, stacks->a_size);
// 	// 마지막에 b stack을 비워주기.
// 	while (stacks->b)
// 		push(stacks, A);
// 	return (1);
// }
