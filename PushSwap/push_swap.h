/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/24 15:34:53 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h> // remove !

# define ERROR "Error"
# define STACK_N "Stacks is NULL"
# define STACK_NM_ERROR "Stack Name Error"
# define NO_REVERSE -1
# define A 'A'
# define B 'B'
# define ALL 'Z'

typedef	struct	s_stacks
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
}				t_stacks;
/*
	** stack funcs
*/
void	push(t_stacks *stacks, char name);
void	rotate(t_stacks *stacks, char name, int is_reverse);
void	swap(t_stacks *s, char name);
/*
	** error
*/
int			error_occur();
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
int			duplicate_check(t_list **list, int num);

/*
	** utils
*/
int		check_stacks(t_stacks *stacks, char num);
void	size_add(t_stacks *stacks, char num);
void	size_minus(t_stacks *stacks, char num);
void	swap_content(void **data1, void **data2);

/*
	** sort
*/
void	merge_sort(t_stacks *stacks, int left, int right);


/*
	** test_funcs
*/
void		test(t_stacks *stacks);

# endif