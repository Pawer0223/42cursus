/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 18:43:17 by taesan           ###   ########.fr       */
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
