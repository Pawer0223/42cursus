/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:33:42 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 01:32:49 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_funcs.h"
#include <stdio.h>

void	swap_exec(t_list **stack)
{
	t_list	*start;
	void 	*temp;

	if (!stack) {
		printf("stack is null\n");
		return;
	}
	start = *stack;
	if (!start) {
		printf("start is null\n");
		return ;
	}
	temp = start->content;
	start->content = start->next->content;
	start->next->content = temp;
}

int		swap_pos(t_list *stack, int size)
{
	if (!stack || size < 2)
		return (0);
	return (1);
}

void	swap(t_stacks *s, char name)
{
	if (name == A && swap_pos(s->a, s->a_size))
		swap_exec(&s->a);
	else if (name == B && swap_pos(s->b, s->b_size))
		swap_exec(&s->b);
	else if (name == ALL)
	{
		if (swap_pos(s->a, s->a_size))
			swap_exec(&s->a);
		if (swap_pos(s->b, s->b_size))
			swap_exec(&s->b);
	}
}
