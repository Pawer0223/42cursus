/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:48:51 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 19:04:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **input)
{
	int i;

	if (!input || !*input)
		return ;
	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
	input = 0;
}

void	free_stacks(t_stacks *stacks)
{
	int i;

	if (!stacks)
		return ;
	if (stacks->a)
		ft_lstclear(&stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b);
	if (stacks->sorted)
	{
		i = 0;
		while (i < stacks->a_size)
			free(stacks->sorted[i++]);
		free(stacks->sorted);
	}
	stacks->sorted = 0;
	stacks->a = 0;
	stacks->b = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->tree_level = 0;
	free(stacks);
}

void	heap_clean(t_stacks *stacks, char **input)
{
	free_stacks(stacks);
	free_input(input);
}