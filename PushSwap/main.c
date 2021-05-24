/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 20:06:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		three(t_stacks **stacks)
{
	int		arr[3];
	int		seq;
	t_list	*stack;

	seq = 0;
	stack = (*stacks)->a;
	while (stack)
	{
		arr[seq++] = *(int *)stack->content;
		stack = stack->next;
	}
	if (arr[1] < arr[2])
	{
		if (arr[0] == 1)
			return (0);
	}
	return (1);
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
	test(stacks); // for test
	/* 
		** list만드는 것 까지 했고, 이제 실제로 stack두개로 코드 적용하는거 만들어야 함.
	*/
	// if (argc == 4)
	// {
	// 	printf("#1\n");
	// 	three(&stacks);
	// }
	free_stacks(stacks);
}
