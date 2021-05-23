/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:53:09 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 14:28:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_list **add_stack, t_list **rm_stack)
{
	t_list *temp;

	temp = *rm_stack;
	*rm_stack = (*rm_stack)->next;
	temp->next = *add_stack;
	*add_stack = temp;
}

int		pa(t_stacks *stacks)
{
	if (!stacks->b || !stacks->b_size)
		return (0);
	swap_stack(&stacks->a, &stacks->b);
	return (1);
}

int		pb(t_stacks *stacks)
{
	if (!stacks->a || !stacks->a_size)
		return (0);
	swap_stack(&stacks->b, &stacks->a);
	return (1);
}

void	push(t_stacks *stacks, char name)
{
	char	minus;
	int		res;

	res = 0;
	minus = (name == A) ? B : A;
	if (name == A)
		res = pa(stacks);
	else if (name == B)
		res = pb(stacks);
	if (res)
	{
		size_add(stacks, name);
		size_minus(stacks, minus);
	}
}
