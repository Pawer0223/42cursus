/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:53:09 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 20:22:44 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		pa(t_stacks *stacks)
{
	if (!stacks->b || !stacks->b_size)
		return (0);
	swap(&stacks->a, &stacks->b);
	return (1);
}

int		pb(t_stacks *stacks)
{
	if (!stacks->a || !stacks->a_size)
		return (0);
	swap(&stacks->b, &stacks->a);
	return (1);
}

