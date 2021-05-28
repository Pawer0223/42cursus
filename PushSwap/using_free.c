/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:48:51 by taesan            #+#    #+#             */
/*   Updated: 2021/05/28 15:45:39 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		ft_lstclear(&stacks->a, &delete_content);
	if (stacks->b)
		ft_lstclear(&stacks->b, &delete_content);
	stacks->a = 0;
	stacks->b = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->tree_level = 0;
	stacks->min = 0;
	stacks->max = 0;
	free(stacks);
}