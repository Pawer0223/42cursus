/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:53:09 by taesan            #+#    #+#             */
/*   Updated: 2021/06/02 17:55:09 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list_db **add_stack, t_list_db **rm_stack)
{
	ft_lstadd_front(add_stack, pop(rm_stack));
}

void	push(t_stacks *stacks, char name)
{
	t_list_db	**add_stack;
	t_list_db	**rm_stack;
	int			rm_stack_size;
	char		other;

	other = opposite(name);
	add_stack = (name == A) ? &stacks->a : &stacks->b;
	rm_stack = (name == A) ? &stacks->b : &stacks->a;
	rm_stack_size = (name == A) ? stacks->b_size : stacks->a_size;
	if (!rm_stack || rm_stack_size == 0)
		return ;
	swap_stack(add_stack, rm_stack);
	size_add(stacks, name);
	size_minus(stacks, other);
	print_inst(PUSH, name);
}
