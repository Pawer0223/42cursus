/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:53:09 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 13:54:55 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **add_stack, t_list **rm_stack)
{
	t_list *temp;

	temp = *rm_stack;
	*rm_stack = (*rm_stack)->next;
	temp->next = *add_stack;
	*add_stack = temp;
}

void	push(t_stacks *stacks, char name)
{
	t_list	**add_stack;
	t_list	**rm_stack;
	int		rm_stack_size;
	char	other;

	other = (name == A) ? B : A;
	add_stack = (name == A) ? &stacks->a : &stacks->b;
	rm_stack = (name == A) ? &stacks->b : &stacks->a;
	rm_stack_size = (name == A) ? stacks->b_size : stacks->a_size;
	if (!rm_stack || rm_stack_size == 0)
		return ;
	swap_stack(add_stack, rm_stack);
	size_add(stacks, name);
	size_minus(stacks, other);
}
