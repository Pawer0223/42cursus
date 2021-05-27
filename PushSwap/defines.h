/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:48:51 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 21:02:33 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include "libft/libft.h"

# define ERROR "Error"
# define STACK_N "Stacks is NULL"
# define STACK_NM_ERROR "Stack Name Error"
# define NO_REVERSE -1
# define A 'A'
# define B 'B'
# define ALL 'Z'
# define ROTATE "rotate"
# define ROTATE_R "rotate_r"
# define PUSH "push"
# define SWAP "swap"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/*
	for sort
*/
typedef	struct	s_sort
{
	int		idx_l;
	int		idx_r;
	int		idx_m;
	int		level;
	int		block_cnt;
	int		*sorted_size;
	int		*data_size;
	char	data_nm;
	char	sorted_nm;
	t_list	**data;
	t_list	**sorted;
}				t_sort;

typedef	struct	s_stacks
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
	int		tree_level;
	int		min;
	int		max;
}				t_stacks;

#endif