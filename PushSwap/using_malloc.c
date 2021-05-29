/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/05/29 18:00:01 by taesan           ###   ########.fr       */
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

int			make_stack(t_list **list, int *len, char **input)
{
	int		*num;
	t_list	*data;

	while (input[*len])
	{
		if (!(num = check_param(input[*len])))
			return (0);
		if (duplicate_check(list, *num) || !(data = ft_lstnew(num)))
		{
			free(num);
			return (0);
		}
		if (*len == 0)
			*list = data;
		else
			ft_lstadd_back(list, data);
		*len += 1;
	}
	return (1);
}

int			make_sorted_data(t_stacks *stacks)
{
	int		**temp;
	int		i;
	t_list	*stack;

	if (!(stacks->sorted = (int **)malloc(sizeof(int *) * stacks->a_size)))
		return (0);
	if (!(temp = (int **)malloc(sizeof(int *) * stacks->a_size)))
		return (0);
	i = 0;
	stack = stacks->a;
	while (stack)
	{
		if (!(stacks->sorted[i] = make_num(*(int *)stack->content)))
		{
			free(temp);
			return (0);
		}
		i++;
		stack = stack->next;
	}
	merge_sort(stacks->sorted, temp, 0, stacks->a_size - 1);
	free(temp);
	return (1);
}

int			init_stacks(t_stacks **stacks, char **input)
{
	if (!(*stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (0);
	(*stacks)->a = 0;
	(*stacks)->b = 0;
	(*stacks)->a_size = 0;
	if (!make_stack(&(*stacks)->a, &(*stacks)->a_size, input))
		return (0);
	(*stacks)->tree_level = ft_sqrt((*stacks)->a_size);
	(*stacks)->b_size = 0;
	if (!make_sorted_data(*stacks))
		return (0);
	// for (int i = 0; i < (*stacks)->a_size; i++)
	// 	printf("%d => ", *(*stacks)->sorted[i]);
	return (1);
}
