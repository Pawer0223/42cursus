/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 17:42:36 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	**	1. stack a->b sorting-push desc
	**	2. last stack b->a sorting-push asc
*/
void	init_sort_info(t_stacks *stacks, t_sort *info)
{
	int	level;

	info->block_cnt = info->idx_r - info->idx_l + 1;
	level = stacks->tree_level - ft_sqrt(info->block_cnt);
	info->level = level;
	info->data_nm = (level != 0 || stacks->tree_level == 1) ? A : B;
	info->data_size = (info->data_nm == A) ? &stacks->a_size : &stacks->b_size;
	info->sorted_nm = (*info->data_size <= 3) ? A : opposite(info->data_nm);
	info->sorted_size = (info->sorted_nm == A) ? &stacks->a_size : &stacks->b_size;
	info->data = (info->data_nm == A) ? &stacks->a : &stacks->b;
	info->sorted = (info->sorted_nm == A) ? &stacks->a : &stacks->b;
	// printf("level : %d, [빈 공간으로 사용될 스택 : %c]\n",level, info->sorted_nm);
}

int		check_order_end(char name, int value, int push_d)
{
	if (name == B && value < push_d) // b로 옮길땐 오름차순
		return (1);
	else if (name == A && value > push_d) // a로 옮길땐 내림차순
		return (1);
	return (0);
}

int		get_insert_idx(t_sort *info, int push_d)
{
	int		idx;
	int		value;
	t_list	*temp;

	temp = *info->sorted;
	idx = 0;
	while (temp)
	{
		value = *(int *)temp->content;
		if (check_order_end(info->sorted_nm, value, push_d))
			break ;
		temp = temp->next;
		idx++;
	}
	return (idx);
}

void	sorting_push(int idx, t_stacks *stacks, t_sort *info)
{
	int	cnt;
	int	size;

	size = *info->sorted_size;
	if (idx <= 1 || idx == size)
		push(stacks, info->sorted_nm);
	if (idx == 1)
		swap(stacks, info->sorted_nm);
	else if (idx == size)
		rotate(stacks, info->sorted_nm, NO_REVERSE);
	else if (idx > (size / 2))
	{
		cnt = size - idx;
		loop_rotate(stacks, info->sorted_nm, cnt, 1);
		push(stacks, info->sorted_nm);
		loop_rotate(stacks, info->sorted_nm, cnt + 1, NO_REVERSE);
	}
	else if (idx <= (size / 2) && idx > 1)
	{
		loop_rotate(stacks, info->sorted_nm, idx, NO_REVERSE);
		push(stacks, info->sorted_nm);
		loop_rotate(stacks, info->sorted_nm, idx, 1);
	}
}

void	int_swap(int i, int j, int data[3])
{
	int temp;

	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void	no_push_sort(t_stacks *stacks, t_sort *info)
{
	t_list *stack;
	int		data[3];
	int		i;
	int		min;

	stack = stacks->a;
	if (*info->data_size == 2)
	{
		if (*(int *)stack->content - *(int *)stack->next->content > 0)
			swap(stacks, A);
	}
	else if (*info->data_size == 3)
	{
		i = 0;
		min = INT_MAX;
		while (i < 3)
		{
			data[i++] = *(int *)stack->content;
			stack = stack->next;
			min = ft_min(min, data[i - 1]);
		}
		while (data[0] != min || data[1] > data[2])
		{
			// printf("%d -> %d -> %d\n", data[0], data[1], data[2]);
			// 가장 큰 수부터 정렬해준다. 처음이거나, 중간에 있는 경우
			if (data[0] > data[1] && data[0] > data[2]) // 가장 큰 수가 가장 위에 있을 때
			{
				rotate(stacks, A, NO_REVERSE);
				int_swap(0, 2, data);
			}
			else if (data[1] > data[0] && data[1] > data[2]) // 가장 큰 수가 중간에 있을 때
			{
				rotate(stacks, A, 1);
				int_swap(1, 2, data);
			}
			else if (data[0] > data[1])
			{
				swap(stacks, A);
				int_swap(0, 1, data);
			}
		}
	}
}

int		merge(t_stacks *stacks, t_sort *info)
{
	int	insert_idx;
	int	push_cnt;

	init_sort_info(stacks, info);
	if (info->data_nm == A && *info->data_size <= 3)
		no_push_sort(stacks, info);
	else
	{
		push_cnt = info->block_cnt - *info->sorted_size;
		while (push_cnt > 0)
		{
			if (!info->sorted)
				push(stacks, info->sorted_nm);
			else
			{
				//printf("data : %c, sorted : %c\n", info->data_nm, info->sorted_nm);
				insert_idx = get_insert_idx(info, peek(*info->data));
				//printf("push data : %d --> insert idx : %d\n",peek(*info->data), insert_idx);
				sorting_push(insert_idx, stacks, info);
			}
			// print_stack(stacks);
			push_cnt--;
		}
	}
	return (1);
}

int		merge_sort(t_stacks *stacks, int idx_l, int idx_r)
{
	int		mid;
	t_sort	info;

	if (idx_l < idx_r)
	{
		info.idx_l = idx_l;
		info.idx_r = idx_r;
		mid = (idx_l + idx_r) / 2;
		info.idx_m = mid;
		if (!merge_sort(stacks, idx_l, mid))
			return (0);
		if (!merge_sort(stacks, mid + 1, idx_r))
			return (0);
		// printf("------------- %d ~ %d merge -------------\n", idx_l, idx_r);
		if (!merge(stacks, &info))
			return (0);
		//print_stack(stacks);
	}
	return (1);
}
