/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/02 14:52:00 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorted_fill(int **sorted, int **temp, t_sort *info)
{
	while (info->idx_l <= info->idx_r)
	{
		sorted[info->idx_l] = temp[info->idx_l];
		info->idx_l++;
	}	
}

void		remain_fill(int **sorted, int **temp, t_sort *info)
{
	if (info->curr_l > info->idx_m)
	{
		while (info->curr_r <= info->idx_r)
			temp[info->k++] = sorted[info->curr_r++];
	}
	else
	{
		while (info->curr_l <= info->idx_m)
			temp[info->k++] = sorted[info->curr_l++];
	}
}

void		compare_fill(int **sorted, int **temp, t_sort *info)
{
	while (info->curr_l <= info->idx_m && info->curr_r <= info->idx_r)
	{
		if (*sorted[info->curr_l] <= *sorted[info->curr_r])
			temp[info->k++] = sorted[info->curr_l++];
		else
			temp[info->k++] = sorted[info->curr_r++];
	}
}
void		merge(int **sorted, int **temp, t_sort *info)
{
	info->curr_l = info->idx_l;
	info->curr_r = info->idx_m + 1;
	info->k = info->idx_l;

	compare_fill(sorted, temp, info);
	remain_fill(sorted, temp, info);
	sorted_fill(sorted, temp, info);
}

void		merge_sort(int **sorted, int **temp, int idx_l, int idx_r)
{
	int		mid;
	t_sort	info;

	if (idx_l < idx_r)
	{
		mid = (idx_l + idx_r) / 2;
		info.idx_l = idx_l;
		info.idx_r = idx_r;
		info.idx_m = mid;
		merge_sort(sorted, temp, idx_l, mid);
		merge_sort(sorted, temp, mid + 1, idx_r);
		merge(sorted, temp, &info);
	}
}
