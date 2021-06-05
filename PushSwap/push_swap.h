/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/06/06 02:00:55 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "doubly_linked_list/double_list.h"
# include "libft/libft.h"
# include "defines.h"
# include <limits.h>
# include <stdio.h> // remove !

/*
	** stack funcs
*/
void		push(t_stacks *stacks, char name);
void		rotate(t_stacks *stacks, char name, int is_reverse);
void		loop_rotate(t_stacks *stacks, char name, int cnt, int is_reverse);
void		swap(t_stacks *s, char name);
void		swap_if(t_stacks *s, char name);
/*
	** error
*/
int			error_occur();
/*
	** using_malloc
*/
int			*make_num(long long num);
int			init_stacks(t_stacks **stacks, char **input);
/*
	** using_free
*/
void		free_stacks(t_stacks *stacks);
void		free_input(char **input);
void		heap_clean(t_stacks *stacks, char **input);
/*
	** checks
*/
int			check_param(char *str);
int			duplicate_check(t_list_db *list, int num);
int			check_sorted(t_list_db *stack, int size);
/*
	** utils
*/
void		size_add(t_stacks *stacks, char num);
void		size_minus(t_stacks *stacks, char num);
char		opposite(char c);
/*
	** sort
*/
void		merge_sort(int **sorted, int **temp, int idx_l, int idx_r);
void		quick_sort(t_stacks *stacks);
void		sorting_push_b_to_a(t_stacks *stacks);
/*
	** common
*/
void		print_inst(char *instruction, char name);
/*
	** below_four
*/
void		below_five(t_stacks *stacks);
/*
	** test_funcs
*/
void		test(t_stacks *stacks);
void		print_li(void *content);
void		print_stack(t_stacks *stacks);

# endif