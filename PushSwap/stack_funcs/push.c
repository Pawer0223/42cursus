/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:53:09 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 19:53:04 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks *stacks)
{
	if (!stacks->b || !stacks->b_size)
		return ;
	swap(&stacks->a, &stacks->b);
}

void	pb(t_stacks *stacks)
{
	if (!stacks->a || !stacks->a_size)
		return ;
	swap(&stacks->b, &stacks->a);
}

