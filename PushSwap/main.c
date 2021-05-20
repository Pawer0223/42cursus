/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 20:24:45 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h> // remove !

void print_stack(t_stacks *stacks)
{
	printf("--- stack A ---\n");
	ft_lstiter(stacks->a, &print_list); // for test
	printf("a size => [%d]\n", stacks->a_size);
	printf("--- stack B ---\n");
	ft_lstiter(stacks->b, &print_list); // for test
	printf("b size => [%d]\n", stacks->b_size);
}

void test(t_stacks *stacks) {


	printf("[ 최초 Stack ]\n");
	print_stack(stacks);

	while (1)
	{
		char inst[20];

		printf("명령어 입력 해주세요. (exit 입력시 종료)\n");
		printf("가능한 명령어 : [pa, pb]\n");
		fgets(inst, sizeof(inst), stdin);
		inst[strlen(inst) - 1] = 0;
		if (ft_strcmp(inst, "exit") == 0)
			break;
		else if (ft_strcmp(inst, "pa") == 0)
			push(stacks, A);
		else if (ft_strcmp(inst, "pb") == 0)
			push(stacks, B);
		else {
			continue ;
		}
		printf("[%s] 수행 결과\n", inst);
		print_stack(stacks);
	}
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
		test(stacks);
		/* 
			** list만드는 것 까지 했고, 이제 실제로 stack두개로 코드 적용하는거 만들어야 함.
		*/
	}
	free_stacks(stacks);
}
