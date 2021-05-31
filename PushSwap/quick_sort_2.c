/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/31 21:46:52 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	피벗 기준으로 작은수를 B로 큰수를 A로 저장.

	stacks->a ==> pivot >= value 
	stacks->b ==> pivot < value
*/
void		partition(t_stacks *stacks, int idx_l, int idx_r, int mid)
{
	int		pivot;

	pivot = *stacks->sorted[mid];

	printf("idx_l : %d ~ idx_r : %d --> sorted[%d] : %d \n", idx_l, idx_r, mid, pivot);

	/* pivot 값을 기준으로 작은 값, 큰 값을 나눔.
		 나눈다 = 대충 정렬
		 최소단위로 쪼개졌다 = 자연스럽게 정렬 끝
		 병합따위 필요 없음.
	*/
	/*
		범위에서 pivot을 찾을 수 있다.

		pivot을 기준으로 stack
	*/


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

}
