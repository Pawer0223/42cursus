/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:33:42 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 15:22:22 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_if(t_stacks *s, char name)
{
	t_list_db	*stack;

	stack = (name == A) ? s->a : s->b;
	if (stack->value - stack->next->value > 0)
		swap(s, name);
}

void	swap_exec(t_list_db **stack)
{
	t_list_db	*start;
	int			temp;

	if (!stack || !*stack)
		return;
	start = *stack;
	temp = start->value;
	start->value = start->next->value;
	start->next->value = temp;
}

int		swap_param_check(t_list_db *stack, int size)
{
	if (!stack || size < 2)
		return (0);
	return (1);
}

void	swap(t_stacks *s, char name)
{
	if (name == A && swap_param_check(s->a, s->a_size))
		swap_exec(&s->a);
	else if (name == B && swap_param_check(s->b, s->b_size))
		swap_exec(&s->b);
	else if (name == ALL)
	{
		if (swap_param_check(s->a, s->a_size))
			swap_exec(&s->a);
		if (swap_param_check(s->b, s->b_size))
			swap_exec(&s->b);
	}
	print_inst(SWAP, name);
}
