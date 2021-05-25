/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/25 19:43:52 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_info(t_list *stack, t_sort *info)
{
	info->curr_l = info->idx_l;
	info->curr_r = info->idx_m + 1;
	info->left = get_list(&stack, info->curr_l);
	info->right = get_list(&stack, info->curr_r);
	info->sorted = 0;
}

void	exec_merge(t_list *stack, t_sort *info)
{
	t_list *temp;

	info->left = get_list(&stack, info->idx_l);
	temp = info->sorted;
	while (temp)
	{
		info->left->content = temp->content;
		info->left = info->left->next;
		temp = temp->next;
	}
}

int		merge(t_stacks *stacks, t_sort *info)
{
	t_list	*temp;
	int		start;
	int		end;

	init_sort_info(stacks->a, info);
	if (!compare(info, &info->curr_l, &info->curr_r))
		return (0);
	start = (info->curr_l > info->idx_m) ? info->curr_r : info->curr_l;
	end = (info->curr_l > info->idx_m) ? info->idx_r : info->idx_m;
	temp = (info->curr_l > info->idx_m) ? info->right : info->left;
	if (!remain_fill(start, end, info->sorted, temp))
		return (0);
	exec_merge(stacks->a, info);
	return (1);
}
/*
	분할은 log2^n번일어남
	16일 때 -> n = 2^4 -> 4번 -> [16 -> 8 -> 4 -> 2 -> 1]
	9일 때 -> n = 2^3보다 크니깐 -> 4번 -> [9 -> 5 -> 3 -> 2 -> 1]
	8일 때 -> n = 2^3 -> 3번 -> [8 -> 4 -> 2 -> 1]
	12 -> [12 -> 6 -> 3 -> 2 -> 1]

	맨 밑에부터 병합하면서 올라옴

	병합해야 할 원소의 갯수에서, 좌, 우측은 정렬을 수행한 후 다음 level로 올라가고 있음.
	[ left ~ mid , mid + 1 ~ right] 반복

	분할 된 갯수가 1개일 때

	분할 된 갯수가 2개일 때

	분할 된 갯수가 4(3)개일 때

	분할된 갯수가 8(5~7)개일 때

	...

	이런식으로 감.

	


*/
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
		printf("%d ~ %d [%d] 개 merge !\n", idx_l, idx_r, (idx_r - idx_l) + 1 );
		if (!merge(stacks, &info))
			return (0);
		ft_lstclear(&info.sorted, &disconnect_content);
	}
	return (1);
}
