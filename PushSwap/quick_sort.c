// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
// /*   Updated: 2021/05/31 19:31:27 by taesan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int		get_insert_idx(t_stacks *stacks, char name, int push_d)
// {
// 	int		idx;
// 	int		value;
// 	t_list	*stack;
	
// 	stack = (name == A) ? stacks->a : stacks->b;
// 	idx = 0;
// 	while (stack)
// 	{
// 		value = *(int *)stack->content;
// 		if (name == B && value < push_d)
// 			return (idx);
// 		if (name == A && value > push_d)
// 			return (idx);
// 		stack = stack->next;
// 		idx++;
// 	}
// 	return (idx);
// }

// void	sorting_push(t_stacks *stacks, int idx, char name)
// {
// 	int	cnt;
// 	int	size;

// 	size = (name == A) ? stacks->a_size : stacks->b_size;
// 	if (idx <= 1 || idx == size)
// 		push(stacks, name);
// 	if (idx == 1) // 첫번째 넣는 경우.. 무조건 swap
// 		swap(stacks, name);
// 	else if (idx == size && size > 1) // 마지막에 넣는데, 2개이상인 경우.. push -> 위로 한칸
// 		rotate(stacks, name, NO_REVERSE);
// 	else if (idx > (size / 2)) // 삽입 위치가 중간 이상이면, 내려가서 위치찾고, push하고 올라가기.
// 	{
// 		cnt = size - idx;
// 		loop_rotate(stacks, name, cnt, 1);
// 		push(stacks, name);
// 		loop_rotate(stacks, name, cnt + 1, NO_REVERSE);
// 	}
// 	else if (idx <= (size / 2) && idx > 1) // 삽입 위치가 중간 이하이면서, 인덱스가 1초과 (앞의 조건에서 push중복 안되도록)
// 	{
// 		loop_rotate(stacks, name, idx, NO_REVERSE);
// 		push(stacks, name);
// 		loop_rotate(stacks, name, idx, 1);
// 	}
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
// int		partition(t_stacks *stacks, int idx_l, int idx_r)
// {
// 	int pivot;

// 	int	i;
// 	int	data;
// 	int	last;
// 	int	insert_idx;
// 	int	size;
// 	// 현재 범위에서 실제, 중간 값.
// 	pivot = *stacks->sorted[((idx_l + idx_r) / 2)];
// 	size = idx_r - idx_l + 1;
// 	// printf("\npivot : %d, size : %d\n", pivot, size);
// 	// pivot이하의 값을 B로 내림차순하며 보낸다.
// 	i = 0;
// 	last = *(int *)ft_lstlast(stacks->a)->content;
// 	while (stacks->a && i < size)
// 	{
// 		data = *(int *)stacks->a->content;
// 		// printf("pivot [%d] ---> working data : %d  || size : %d ---> i : %d\n", pivot, data, size, i);
// 		if (data <= pivot) // b에 넣어야하는경우,  pivot이하 내림차순.
// 		{
// 			if (stacks->b && data < peek(stacks->b))
// 			{
// 				insert_idx = get_insert_idx(stacks, B, peek(stacks->a));
// 				sorting_push(stacks, insert_idx, B);
// 			}
// 			else
// 				push(stacks, B);
// 		}
// 		// stack A에 오름차순해서 저장하고 있는다.
// 		else
// 		{
// 			if (i == size - 1 && data < last) // 오름차순정렬할 때, 마지막 값은 끝의 값보다 작으면 안바꿈 , because 정렬하고있으니깐
// 				break;
// 			if (stacks->a_size <= 3)
// 			{
// 				no_push_sort(stacks);
// 				break;
// 			}
// 			// 마지막 값이 더 작을 때 위로올리면, 3 . . . . 2 일 때 => . . . 2 3 이렇게 됨.
// 			// 따라서 마지막 값이 더 크다면 ? 2 . . . 3일때 => 3 2 . . . 해서 swap하고 2 3 . . . 만들어서 두개를 밑으로 보내주기 . . . 2 3
// 			// if (last > pivot && last > data)
// 			// {
// 			// 	rotate(stacks, A, 1);
// 			// 	swap(stacks, A);
// 			// 	rotate(stacks, A, NO_REVERSE);
// 			// }
// 			// else
// 			// 	last = data;
// 			rotate(stacks, A, NO_REVERSE);
// 		}
// 		if (check_sorted(stacks->a, stacks->a_size))
// 		{
// 			while (stacks->b)
// 			{
// 				insert_idx = get_insert_idx(stacks, A, peek(stacks->b));
// 				sorting_push(stacks, insert_idx, A);				
// 			}
// 			return (1);
// 		}
// 		// print_stack(stacks);
// 		i++;
// 	}
// 	// 재귀 해야 함..
// 	// 마지막에 b stack을 비워주기.
// 	return (1);
// }

// int		quick_sort(t_stacks *stacks, int idx_l, int idx_r)
// {
// 	// 중간 값을 기준으로 분할 정렬.
// 	// int pivot_idx;

// 	while (idx_l < idx_r)
// 	{
// 		int mid;
// 		// printf("----------------------- %d ~ %d -----------------------\n", idx_l , idx_r);
// 		partition(stacks, idx_l, idx_r);
// 		// 큰 값이 모두 넘어간 상태로 정렬이 되어 있으면 종료지점이다.
// 		if (check_sorted(stacks->a, stacks->a_size))
// 			break ;
// 		// print_stack(stacks);
// 		mid = (idx_l + idx_r) / 2;
// 		idx_l = mid + 1;
// 	}
// 	while (stacks->b)
// 		push(stacks, A);
// 	// print_stack(stacks);
// 	return (1);
// }
