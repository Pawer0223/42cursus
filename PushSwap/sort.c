/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 21:40:14 by taesan           ###   ########.fr       */
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

int		compare(t_sort *info, int *i, int *j)
{
	t_list *add_list;

	while (info->left && info->right && *i <= info->idx_m && *j <= info->idx_r)
	{
		if (*(int *)(info->left->content) - *(int *)(info->right->content) <= 0)
		{
			add_list = info->left;
			info->left = info->left->next;
			*i += 1;
		}
		else
		{
			add_list = info->right;
			info->right = info->right->next;
			*j += 1;
		}
		if (!(add_list = ft_lstnew(add_list->content)))
			return (0);
		ft_lstadd_back(&info->sorted, add_list);
	}
	return (1);
}

int		remain_fill(int start, int end, t_list *sorted, t_list *remain)
{
	t_list	*add_list;

	while (start <= end)
	{
		if (!(add_list = ft_lstnew(remain->content)))
			return (0);
		ft_lstadd_back(&sorted, add_list);
		remain = remain->next;
		start++;
	}
	return (1);
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
	info->left = get_list(&stacks->a, info->idx_l);
	temp = info->sorted;
	while (temp)
	{
		info->left->content = temp->content;
		info->left = info->left->next;
		temp = temp->next;
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
		if (!merge(stacks, &info))
			return (0);
		ft_lstclear(&info.sorted, &disconnect_content);
	}
	return (1);
}
