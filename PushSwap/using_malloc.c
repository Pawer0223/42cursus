/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 18:56:37 by taesan           ###   ########.fr       */
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

void	test_stack_b(t_stacks **s)
{
	t_list *list;
	int	i;

	list = ft_lstnew(make_num(20));
	if (!list)
		return ;
	i = 30;
	while (i < 70) {
		ft_lstadd_front(&list, ft_lstnew(make_num(i)));
		i += 10;
	}
	(*s)->b = list;
}

int			init_list(t_list **list, int argc, const char *argv[])
{
	int		i;
	int		*num;
	t_list	*data;

	i = 1;
	while (i < argc)
	{
		if (!(num = check_param(argv[i])))
			return (0);
		if (!(data = ft_lstnew(num)))
		{
			free(num);
			return (0);
		}
		if (i == 1)
			*list = data;
		else
			ft_lstadd_front(list, data);
		i++;
	}
	return (1);
}

int			init_stacks(t_stacks **stacks, int argc, const char *argv[])
{
	t_list *list;

	list = 0;
	if (!(*stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (0);
	if (!init_list(&list, argc, argv))
		return (error_occur(&list));
	(*stacks)->a = list;
	(*stacks)->b = 0;
	(*stacks)->a_size = argc - 1;
	(*stacks)->b_size = 0;
	// test
	test_stack_b(stacks);
	(*stacks)->b_size = 5;
	return (1);
}
