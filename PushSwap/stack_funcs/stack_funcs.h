/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:09:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 14:31:57 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNCS_H
# define STACK_FUNCS_H

# include "../defines.h"

// sa
// sb
// ss
// pa
// pb
int		pa(t_stacks *stacks);
int		pb(t_stacks *stacks);

// ra
// rb
// rr
// rra
// rrb
// rrr

/*
	** utils
*/
int		check_stacks(t_stacks *stacks, char num);
void	size_add(t_stacks *stacks, char num);
void	size_minus(t_stacks *stacks, char num);
void	swap_content(void **data1, void **data2);


# endif