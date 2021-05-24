/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 15:26:52 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_stacks *stacks, int l, int m, int r)
{
	t_list *sorted;

	printf("l : %d, m : %d, r : %d\n", l, m, r);
	sorted = get_list(&stacks->a, l);
	printf("%d content [%d]\n", l , *(int *)sorted->content);



	// sorted = stack_a;
}

void	merge_sort(t_stacks *stacks, int left, int right)
{
	int	mid;
	
	if (left < right){
		mid = (left + right) / 2;
		merge_sort(stacks, left, mid); // 왼쪽
		merge_sort(stacks, mid + 1, right); // 오른쪽
		merge(stacks, left, mid, right);
	}
}
