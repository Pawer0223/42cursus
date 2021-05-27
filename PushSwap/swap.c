/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:33:42 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 18:20:29 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_if(t_stacks *s, char name)
{
	t_list	*stack;

	stack = (name == A) ? s->a : s->b;
	if (*(int *)stack->content - *(int *)stack->next->content > 0)
		swap(s, name);
}

void	swap_exec(t_list **stack)
{
	t_list	*start;

	if (!stack || !*stack)
		return;
	start = *stack;
	swap_content(&start->content, &start->next->content);
}

int		swap_param_check(t_list *stack, int size)
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
