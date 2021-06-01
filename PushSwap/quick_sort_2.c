/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 15:30:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		send_a_to_b_desc(t_list_db **start, int pivot, int size)
{
	int		data;
	t_list_db	*last;

	last = ft_lstlast(*start);
	while (size > 0)
	{
		data = (*start)->value;
		if (data < pivot)
		{
			// 상단에서부터 pivot미만의 값.

			// 하단에서부터 pivot미만의 값. 찾은 후.

			// 더 빨리 보낼 수 있는것부터 보낸다.

			// 
		
		}
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
	int		pivot;
	int		size;

	pivot = *stacks->sorted[mid];

	// printf("idx_l : %d ~ idx_r : %d --> sorted[%d] : %d \n", idx_l, idx_r, mid, pivot);
	size = idx_r - idx_l + 1;
	// 크기 범위에서 pivot 미만의 값 찾기.

	//send_a_to_b_desc(&stacks->a, pivot, (idx_r - idx_l + 1));



}

void		quick_sort(t_stacks *stacks, int idx_l, int idx_r)
{
	int mid;

	if (idx_l < idx_r)
	{
		mid = (idx_l + idx_r) / 2;

			partition(stacks, idx_l, idx_r, mid);
			quick_sort(stacks, idx_l, mid - 1);
			quick_sort(stacks, mid + 1, idx_r);
	}
}

void	exec_sort(t_stacks *stacks)
{
	quick_sort(stacks, 0, stacks->a_size - 1);

}
