/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:11:26 by taesan            #+#    #+#             */
/*   Updated: 2021/06/03 16:26:54 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_value(t_list_db *v1, t_list_db *v2)
{
	int temp;

	printf("v1 value : %d, v2 value : %d\n", v1->value, v2->value);

	temp = v1->value;
	v1->value = v2->value;
	v2->value = temp;
}

void	loop_rotate(t_stacks *stacks, char name, int cnt, int is_reverse)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		rotate(stacks, name, is_reverse);
		i++;
	}
}

void	exec_rotate(t_list_db **stack, int is_reverse)
{
	t_list_db	*start;
	t_list_db	*last;
	t_list_db	*prev;

	if (!stack || !*stack)
		return ;
	start = *stack;
	last = ft_lstlast(start);
	if (is_reverse == NO_REVERSE)
	{
		*stack = start->next;
		(*stack)->prev = NULL;
		start->next = 0;
		start->prev = last;
		last->next = start;
	}
	else
	{
		prev = last->prev;
		prev->next = NULL;
		last->next = start;
		start->prev = last;
		last->prev = NULL;
		*stack = last;
	}
}

void	rotate(t_stacks *stacks, char name, int is_reverse)
{
	if ((name == A || name == ALL) && stacks->a_size > 1)
		exec_rotate(&stacks->a, is_reverse);
	if ((name == B || name == ALL) && stacks->b_size > 1)
		exec_rotate(&stacks->b, is_reverse);
	if (is_reverse == NO_REVERSE)
		print_inst(ROTATE, name);
	else
		print_inst(ROTATE_R, name);
}
