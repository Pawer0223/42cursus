/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:15:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 15:19:28 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_content(void **data1, void **data2)
{
	void	*temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

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
