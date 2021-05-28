/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:48:51 by taesan            #+#    #+#             */
/*   Updated: 2021/05/29 00:08:39 by taesan           ###   ########.fr       */
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
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		ft_lstclear(&stacks->a, &delete_content);
	if (stacks->b)
		ft_lstclear(&stacks->b, &delete_content);
	if (stacks->sort_stack)
		ft_lstclear(&stacks->b, &delete_content);
	stacks->a = 0;
	stacks->b = 0;
	stacks->sort_stack = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->tree_level = 0;
	stacks->min = 0;
	stacks->max = 0;
	free(stacks);
}

void	heap_clean(t_stacks *stacks, char **input)
{
	free_stacks(stacks);
	free_input(input);
}