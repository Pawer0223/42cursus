/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/23 15:33:15 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "defines.h"
# include "stack_funcs/stack_interfcae.h"
# include <limits.h>
# include <stdio.h> // remove !

/*
	** error
*/
int			error_occur(t_list **list);
void		delete_content(void *content);
/*
	** using_malloc
*/
int			*make_num(long long num);
int			init_list(t_list **list, int argc, const char *argv[]);
int			init_stacks(t_stacks **stacks, int argc, const char *argv[]);

/*
	** using_free
*/
void		free_stacks(t_stacks *stacks);

/*
	** checks
*/
int			*check_param(const char *str);
/*
	** test_funcs
*/
void		test(t_stacks *stacks);

# endif