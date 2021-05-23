/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:11:26 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 13:48:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_funcs.h"

void	exec_rotate_r(t_list **stack)
{
	t_list *start;
	t_list *last;

	if (!stack || !*stack)
		return ;
	start = *stack;
	last = ft_lstlast(start);
	*stack = start->next;
	start->next = 0;
	last->next = start;
}

void	rotate_r(t_stacks *stacks, char name)
{
	if (name == A && stacks->a_size > 1)
		exec_rotate_r(&stacks->a);
	else if (name == B && stacks->b_size > 1)
		exec_rotate_r(&stacks->b);
	else if (name == ALL)
	{
		if (stacks->a_size > 1)
			exec_rotate_r(&stacks->a);
		if (stacks->b_size > 1)
			exec_rotate_r(&stacks->b);
	}
}