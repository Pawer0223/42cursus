/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 15:49:36 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "error.h"
# include "stack_funcs/stack_funcs.h"
# include <limits.h>
# include <stdio.h> // remove !

/*
	**  pa, pb에서 a, b를 구분하기 위함
	** 
*/
typedef	struct	s_stacks
{
	t_list	*a;
	t_list	*b;
}				t_stacks;

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
int			init_stacks(t_stacks **stacks, t_list *stack_a);

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
void		print_list(void *content);

# endif