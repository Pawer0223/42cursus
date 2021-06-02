/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/06/02 18:09:00 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		// edge_check(stacks);
		if(!check_sorted(stacks->a, stacks->a_size))
		{
			if (stacks->a_size <= 3)
				no_push_sort(stacks);
			else
				exec_sort(stacks);
		}
		//print_stack(stacks);
		// 	//merge_sort(stacks, 0, stacks->a_size - 1);
		//test(stacks);
		heap_clean(stacks, input);		
	}
}
