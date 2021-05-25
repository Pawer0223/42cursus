/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/05/25 18:01:46 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*make_num(long long num)
{
	int	*ptr;

	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (!(ptr = (int *)malloc(sizeof(int))))
		return (0);
	*ptr = (int)num;
	return (ptr);
}

int			make_stack_a(t_list **list, int argc, const char *argv[])
{
	int		i;
	int		*num;
	t_list	*data;

	i = 1;
	while (i < argc)
	{
		if (!(num = check_param(argv[i])))
			return (0);
		if (duplicate_check(list, *num) || !(data = ft_lstnew(num)))
		{
			free(num);
			return (0);
		}
		if (i == 1)
			*list = data;
		else
			ft_lstadd_back(list, data);
		i++;
	}
	return (1);
}

int			init_stacks(t_stacks **stacks, int argc, const char *argv[])
{
	if (!(*stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (0);
	(*stacks)->a = 0;
	(*stacks)->b = 0;
	if (!make_stack_a(&(*stacks)->a, argc, argv))
		return (0);
	(*stacks)->a_size = argc - 1;
	(*stacks)->b_size = 0;
	return (1);
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
		/*
			정렬 결과를 sorted에 저장 후, 마지막에 옮기기
		*/
		/*
			정렬하면서, 명령어 수행하기.

			0 ~ mid와
				-> 0 ~ 2까지 정렬 끝, 마지막에 0 ~ 5 정렬 수행.
				-> 0 ~ 2정렬 과정에서,  push가 필요한지.
					-> 이 step에서 정렬이 일어나는 경우,
					-> 하나씩 정렬이 되어 감.
					-> 정렬, 정렬, 정렬, 정렬
					-> 총 10개일 때, 왼쪽은 5개
					  -> 1개1개정렬 -> 2개(sorted) + 1개 정렬 -> 3개(sorted) + 2개 정렬
					  -> 


			mid + 1 ~ right 의 정렬이 반복된다.
				->
			
		*/
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
