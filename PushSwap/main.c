/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/28 16:11:06 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		main(int argc, const char *argv[])
// {
// 	t_stacks	*stacks;

// 	stacks = 0;
// 	if (argc < 2 || !init_stacks(&stacks, argc, argv))
// 	{
// 		free_stacks(stacks);
// 		return (error_occur());
// 	}
// 	edge_check(stacks);
// 	if(!check_sorted(stacks->a, stacks->a_size))
// 		merge_sort(stacks, 0, stacks->a_size - 1);
// 	test(stacks);
// 	free_stacks(stacks);
// }

void	test_case_print(int size, const char *arr[])
{
	printf("------------ ");
	for (int i = 1; i < size; i++)
		printf("%s ", arr[i]);
	printf("------------\n");
}

#define CASE_CNT 4

int		main(void)
{
	t_stacks	*stacks;
	int i = 0;
	stacks = 0;

	// argc, argc처럼 쓸라고 처음값 쓰레기 넣기...
	const char *testcase[CASE_CNT][6] = {
		{" ", "4", "67", "3", "87", "23"},
		{" ", "5", "4", "3", "2", "1"},
		{" ", "1", "2", "3", "4", "5"}
		// {"2", "1", "3", "6", "5", "8"},
		// {"3", "2", "1"},
		// {"1"},
		// {"1", "2", "3"}
	};
	
	const char *base_case[7] = {" ", "2", "1", "3", "6", "5", "8"};
	
	// argc의 용도로 쓰였기 때문에 크기 + 1로 지정해야 함
	int arr_len[CASE_CNT] = {6, 6, 6, 7};
	while (i < CASE_CNT)
	{
		if (i == CASE_CNT -1)
		{
			test_case_print(arr_len[i], base_case);
			if (!init_stacks(&stacks, arr_len[i], base_case))
			{
				free_stacks(stacks);
				return (error_occur());
			}
		}
		else
		{
			test_case_print(arr_len[i], testcase[i]);
			if (!init_stacks(&stacks, arr_len[i], testcase[i]))
			{
				free_stacks(stacks);
				return (error_occur());
			}
		}
		edge_check(stacks);
		if(!check_sorted(stacks->a, stacks->a_size))
			merge_sort(stacks, 0, stacks->a_size - 1);
		free_stacks(stacks);
		i++;
	}

}
