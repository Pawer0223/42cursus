/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/05 21:39:25 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exec_sort(t_stacks * stacks)
{
	quick_sort(stacks);
	sorting_push_b_to_a(stacks);
}

int		main(int argc, const char *argv[])
{
	t_stacks	*stacks;
	char		**input;

	if (argc > 1)
	{
		if (!(input = ft_split(argv[1], ' ')))
			return (error_occur());
		stacks = 0;
		if (!init_stacks(&stacks, input))
		{
			heap_clean(stacks, input);
			return (error_occur());
		}
		if(!check_sorted(stacks->a, stacks->a_size))
		{
			if (stacks->a_size <= 5)
				below_five(stacks);
			else
				exec_sort(stacks);
		}
		heap_clean(stacks, input);
	}
}
