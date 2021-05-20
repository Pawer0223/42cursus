/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 19:54:35 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stacks *stacks)
{
	printf("--- stack A ---\n");
	ft_lstiter(stacks->a, &print_list); // for test
	printf("size => [%d]\n", stacks->a_size);
	printf("--- stack B ---\n");
	ft_lstiter(stacks->b, &print_list); // for test
	printf("size => [%d]\n", stacks->b_size);
}

void test(t_stacks *stacks) {
	print_stack(stacks);
}

int		main(int argc, const char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		return (error_occur(0));
	else
	{
		if (!init_stacks(&stacks, argc, argv))
			return (0);
		/* 
			** list만드는 것 까지 했고, 이제 실제로 stack두개로 코드 적용하는거 만들어야 함.
		*/
	}

	test(stacks);
	push(stacks, A);
	push(stacks, A);
	push(stacks, A);
	push(stacks, A);
	push(stacks, A);
	push(stacks, B);





	test(stacks);
	
	free_stacks(stacks);
}
