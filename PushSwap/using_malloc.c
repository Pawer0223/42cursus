/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 19:07:23 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int			*make_num(long long num)
// {
// 	int	*ptr;

// 	if (num < INT_MIN || num > INT_MAX)
// 		return (0);
// 	if (!(ptr = (int *)malloc(sizeof(int))))
// 		return (0);
// 	*ptr = (int)num;
// 	return (ptr);
// }

// int			make_stack(t_list_db **list, int *len, char **input)
// {
// 	int			*num;
// 	t_list_db	*data;

// 	while (input[*len])
// 	{
// 		if (!(num = check_param(input[*len])))
// 			return (0);
// 		if (duplicate_check(list, *num) || !(data = ft_lstnew(num)))
// 		{
// 			free(num);
// 			return (0);
// 		}
// 		if (*len == 0)
// 			*list = data;
// 		else
// 			ft_lstadd_back(list, data);
// 		*len += 1;
// 	}
// 	return (1);
// }
/*
	**	first white space possible
	**	next '-' or '+' possible, next only number
*/
int			my_atoi(char *str)
{
	int			i;
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		flag *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= flag;
	return (result);
}

int			make_stack(t_list_db **list, int *len, char **input)
{
	t_list_db	*data;
	int			value;

	while (input[*len])
	{
		if (!check_param(input[*len]))
			return (0);
		value = my_atoi(input[*len]);
		if (duplicate_check(*list, value) || !(data = ft_lstnew(value)))
			return (0);
		ft_lstadd_back(list, data);
		*len += 1;
	}
	return (1);
}

int			make_sorted_data(t_stacks *stacks)
{
	int			**temp;
	int			*num;
	int			i;
	t_list_db	*stack;

	if (!(stacks->sorted = (int **)malloc(sizeof(int *) * stacks->a_size)))
		return (0);
	if (!(temp = (int **)malloc(sizeof(int *) * stacks->a_size)))
		return (0);
	i = 0;
	stack = stacks->a;
	while (stack)
	{
		if (!(num = (int *)malloc(sizeof(int))))
		{
			free(temp);
			return (0);
		}
		num[0] = stack->value;
		stacks->sorted[i] = num;
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
