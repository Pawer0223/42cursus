/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:53:12 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 16:20:36 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test file is remove !

#include "push_swap.h"
#include <string.h>

void	print_space(int cnt)
{
	for (int i = 0; i < cnt; i++)
		printf(" ");
}

void	print_line(int cnt, void *content, int is_last, int len)
{
	print_space(cnt);
	if (content)
		printf("%d", *(int *)content);
	if (len % 2 != 0)
		cnt++;
	print_space(cnt);
	if (is_last)
		printf("\n");
	else
		printf("||");
}

int		get_len_test(int n)
{
	int len = n < 0 ? 1 : 0;
	while (n != 0) {
		len++;
		n /= 10;
	}
	return len;
}

void	print_list(void *a_content, void *b_content)
{
	// null일 때, 기존 데이터 있는지 없는지
	// 최대 13자리, 
	int total = 20;
	int a = 0;
	int b = 0;
	if (a_content)
		a = *(int *)a_content;
	if (b_content)
		b = *(int *)b_content;
	int a_len, b_len;
	int a_cnt, b_cnt;
	
	a_len = get_len_test(a);
	b_len = get_len_test(b);

	a_cnt = (total - a_len) / 2;
	b_cnt = (total - b_len) / 2;
	// 20 - 2 / 2 => 9
	// 20 - 1 / 2 => 9
	// printf("a_cnt : [%d], b_cnt : [%d]\n", a_cnt, b_cnt);

	// 데이터 자리수만 큼..
	if (!b_content) {
		print_line(a_cnt, a_content, 0, a_len);
		print_line((total / 2), 0, 1, 0);
	}
	else if (!a_content) {
		print_line((total / 2), 0, 0, 0);
		print_line(b_cnt, b_content, 1, b_len);
	}
	else {
		print_line(a_cnt, a_content, 0, a_len);
		print_line(b_cnt, b_content, 1, b_len);
	}
}

void print_stack(t_stacks *stacks)
{
	int min_stack;
	int max_stack;
	int min;
	int max;
	t_list *min_li;
	t_list *max_li;

	if (stacks->a_size < stacks->b_size)
	{
		min = stacks->a_size;
		max = stacks->b_size;
		min_li = stacks->a;
		max_li = stacks->b;
		min_stack = A;
		max_stack = B;
	} else {
		min = stacks->b_size;
		max = stacks->a_size;
		min_li = stacks->b;
		max_li = stacks->a;
		min_stack = B;
		max_stack = A;		
	}
	int min_start = max - min;
	
	// 20 || 20
	printf("------ stackA ------||------ stackB ------\n");
	for (int i = 0; i < max; i++) {

		if (i < min_start) {
			if (max_stack == A) 
				print_list(max_li->content, 0);
		 	else if (max_stack == B)
				print_list(0, max_li->content);
		} else {
			if (max_stack == A) 
				print_list(max_li->content, min_li->content);
			else if (max_stack == B)
				print_list(min_li->content, max_li->content);
			min_li = min_li->next;
		}
		max_li = max_li->next;
	}
}

void	show_command()
{
	printf("push : (pa, pb)\nswap : (sa, sb, ss)\nrotation_up : (ra, rb, rr)\nrotation_down : (rra, rrb, rrr)\nprogram : (exit)\n");
}

int		on_change(int on)
{
	if (on)
	{
		printf("** stack show off **\n");
		return (0);
	}
	else
	{
		printf("** stack show on **\n");
		return (1);
	}
}

void	test(t_stacks *stacks)
{

	int on = 1;

	printf("[ 최초 Stack ]\n");
	print_stack(stacks);

	while (1)
	{
		char inst[20];

		printf("\n명렁어 보기: command, 프로그램 종료: exit, stack 출력 켜기, 끄기: on/off, stack 출력: show\n");
		// show_command();
		fgets(inst, sizeof(inst), stdin);
		inst[strlen(inst) - 1] = 0;
		if (ft_strcmp(inst, "exit") == 0)
			break;
		else if (ft_strcmp(inst, "pa") == 0)
			push(stacks, A);
		else if (ft_strcmp(inst, "pb") == 0)
			push(stacks, B);
		else if (ft_strcmp(inst, "sa") == 0)
			swap(stacks, A);
		else if (ft_strcmp(inst, "sb") == 0)
			swap(stacks, B);
		else if (ft_strcmp(inst, "ss") == 0)
			swap(stacks, ALL);
		else if (ft_strcmp(inst, "ra") == 0)
			rotate(stacks, A, 0);
		else if (ft_strcmp(inst, "rb") == 0)
			rotate(stacks, B, 0);
		else if (ft_strcmp(inst, "rr") == 0)
			rotate(stacks, ALL, 0);
		else if (ft_strcmp(inst, "rra") == 0)
			rotate(stacks, A, 1);
		else if (ft_strcmp(inst, "rrb") == 0)
			rotate(stacks, B, 1);
		else if (ft_strcmp(inst, "rrr") == 0)
			rotate(stacks, ALL, 1);
		else if (ft_strcmp(inst, "command") == 0) {
			show_command();
			continue;
		}
		else if (ft_strcmp(inst, "on") == 0) {
			on = on_change(on);
			continue;
		}
		else if (ft_strcmp(inst, "off") == 0) {
			on = on_change(on);
			continue;
		}
		else if (ft_strcmp(inst, "show") == 0) {
			print_stack(stacks);
			continue;
		}
		else {
			printf("[ %s ]는 존재하지 않는 명령어 입니다.\n", inst);
			continue;
		}
		if (on)
			print_stack(stacks);
	}
}
