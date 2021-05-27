/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:35:22 by taesan            #+#    #+#             */
/*   Updated: 2021/05/26 21:44:44 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_a_print(char *instruction)
{
	if (ft_strcmp(ROTATE, instruction) == 0)
		ft_putendl_fd(RA, 1);
	else if (ft_strcmp(ROTATE_R, instruction) == 0)
		ft_putendl_fd(RRA, 1);
	else if (ft_strcmp(SWAP, instruction) == 0)
		ft_putendl_fd(SA, 1);
	else if (ft_strcmp(PUSH, instruction) == 0)
		ft_putendl_fd(PA, 1);
}

void		stack_b_print(char *instruction)
{
	if (ft_strcmp(ROTATE, instruction) == 0)
		ft_putendl_fd(RB, 1);
	else if (ft_strcmp(ROTATE_R, instruction) == 0)
		ft_putendl_fd(RRB, 1);
	else if (ft_strcmp(SWAP, instruction) == 0)
		ft_putendl_fd(SB, 1);
	else if (ft_strcmp(PUSH, instruction) == 0)
		ft_putendl_fd(PB, 1);
}

void		print_inst(char *instruction, char name)
{
	if (name == A)
		stack_a_print(instruction);
	else if (name == B)
		stack_b_print(instruction);
	else if (name == ALL)
	{
		stack_a_print(instruction);
		stack_b_print(instruction);
	}
}