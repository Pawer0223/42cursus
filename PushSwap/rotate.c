/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:11:26 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 20:20:32 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_prev(t_list *lst)
{
	t_list *prev;

	prev = 0;
	while (lst)
	{
		if (!lst->next)
			return (prev);
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

void	exec_rotate(t_list **stack, int is_reverse)
{
	t_list	*start;
	t_list	*last;
	t_list	*prev;

	if (!stack || !*stack)
		return ;
	start = *stack;
	last = ft_lstlast(start);
	if (is_reverse)
	{
		prev = get_prev(*stack);
		prev->next = 0;
		last->next = start;
		*stack = last;
	}
	else
	{
		*stack = start->next;
		start->next = 0;
		last->next = start;
	}
}

void	rotate(t_stacks *stacks, char name, int is_reverse)
{
	if (name == A && stacks->a_size > 1)
		exec_rotate(&stacks->a, is_reverse);
	else if (name == B && stacks->b_size > 1)
		exec_rotate(&stacks->b, is_reverse);
	else if (name == ALL)
	{
		if (stacks->a_size > 1)
			exec_rotate(&stacks->a, is_reverse);
		if (stacks->b_size > 1)
			exec_rotate(&stacks->b, is_reverse);
	}
}
