/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 19:37:57 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, const char *argv[])
{
	t_stacks	*stacks;

	stacks = 0;
	if (argc < 2 || !init_stacks(&stacks, argc, argv))
	{
		free_stacks(stacks);
		return (error_occur());
	}
	// test(stacks);
	merge_sort(stacks, 0, stacks->a_size - 1);
	test(stacks);
	
	free_stacks(stacks);
}
