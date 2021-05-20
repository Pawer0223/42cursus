/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:15:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 19:53:49 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_funcs.h"

int		check_stacks(t_stacks *stacks, char num)
{
	if (!stacks)
	{
		ft_putendl_fd(STACK_N, 1);
		return (0);
	}
	if (!(num == A || num == B))
	{
		ft_putendl_fd(STACK_NM_ERROR, 1);
		return (0);
	}
	return (1);
}

void	size_add(t_stacks *stacks, char num)
{
	if (!check_stacks(stacks, num))
		return ;
	if (num == A)
		stacks->a_size++;
	else if (num == B)
		stacks->b_size++;
}

void	size_minus(t_stacks *stacks, char num)
{
	if (!check_stacks(stacks, num))
		return ;
	if (num == A && stacks->a_size > 0)
		stacks->a_size--;
	else if (num == B && stacks->b_size > 0)
		stacks->b_size--;
}

void	swap(t_list **add_stack, t_list **rm_stack)
{
	t_list *temp;

	temp = *rm_stack;
	*rm_stack = (*rm_stack)->next;
	temp->next = *add_stack;
	*add_stack = temp;
}