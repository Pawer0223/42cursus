/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 18:21:32 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ordery_by 0 = asc, 1 = desc
*/
int		rotation_sort(t_stacks *stacks)
{
	stacks = 0;
	return (0);
}

int		main(int argc, const char *argv[])
{
	t_stacks	*stacks;

	stacks = 0;
	if (argc < 2 || !init_stacks(&stacks, argc, argv))
	{
		free_stacks(stacks);
		return (error_occur());
	}
	//if (!rotation_sort(stacks))
		merge_sort(stacks, 0, stacks->a_size - 1);
	test(stacks);
	free_stacks(stacks);
}
