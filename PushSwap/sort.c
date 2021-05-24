/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 19:42:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		compare_to(void *a, void *b)
{
	int v1;
	int v2;

	v1 = *(int *)a;
	v2 = *(int *)b;
	return (v1 - v2);
}
/*
	파라미터 범위의 list를 모두 받아와야 함.
*/
int		merge(t_stacks *stacks, int l, int m, int r)
{
	t_list	*left;
	t_list	*right;
	t_list	*sorted;
	t_list	*add_list;

	// printf("l : %d, m : %d, r : %d\n", l, m, r);
	int i;
	int j;

	i = l;
	j = m + 1;

	left = get_list(&stacks->a, l);
	right = get_list(&stacks->a, j);
	sorted = 0;
	
	while (left && right && i <= m && j <= r)
	{
		printf("left : %d, right %d\n", *(int *)left->content, *(int *)right->content);
		if (compare_to(left->content, right->content) <= 0)
		{
			add_list = left;
			left = left->next;
			i++;
		}
		else
		{
			add_list = right;
			right = right->next;
			j++;
		}
		ft_lstadd_back(&sorted, ft_lstnew(add_list->content));
	}

	/*
		** left값으로 sorted를 채운경우, right에남아 있는 값을 채워준다.
	*/
	if (i > m)
	{
		while(j <= r)
		{
			ft_lstadd_back(&sorted, ft_lstnew(right->content));
			right = right->next;
			j++;
		}
	}
	/*
		** right로 sorted를 모두 채운 경우, left에 남아 있는 값을 채워준다.
	*/
	else
	{
		while(i <= m)
		{
			ft_lstadd_back(&sorted, ft_lstnew(left->content));
			left = left->next;
			i++;
		}
	}
	left = get_list(&stacks->a, l);
	t_list *temp = sorted;
	while (sorted)
	{
		left->content = sorted->content;
		left = left->next;
		sorted = sorted->next;
		l++;
	}
	ft_lstclear(&temp, &disconnect_content);
	return (1);
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
