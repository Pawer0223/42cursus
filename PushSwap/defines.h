/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:48:51 by taesan            #+#    #+#             */
/*   Updated: 2021/06/01 17:54:20 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include "libft/libft.h"

# define ERROR "Error"
# define STACK_N "Stacks is NULL"
# define STACK_NM_ERROR "Stack Name Error"
# define NO_REVERSE 0
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
// typedef	struct	s_sort
// {
// 	int		idx_l;
// 	int		idx_r;
// 	int		idx_m;
// 	int		level;
// 	int		block_cnt;
// 	int		*sorted_size;
// 	int		*data_size;
// 	char	data_nm;
// 	char	sorted_nm;
// 	t_list	**data;
// 	t_list	**sorted;
// }				t_sort;

/*
	for sort
*/

typedef	struct	s_sort
{
	//sorted is s_stacks->sorted
	int		idx_l;
	int		idx_r;
	int		idx_m;
	int		curr_l;
	int		curr_r;
	int		k;
}				t_sort;

typedef	struct	s_stacks
{
	t_list_db	*a;
	t_list_db	*b;
	int			**sorted;
	int			a_size;
	int			b_size;
	int			tree_level;
}				t_stacks;

#endif