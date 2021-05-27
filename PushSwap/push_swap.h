/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 21:19:55 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void		delete_content(void *content);
void		disconnect_content(void *content);
/*
	** using_malloc
*/
int			*make_num(long long num);
int			init_list(t_list **list, int argc, const char *argv[]);
int			init_stacks(t_stacks **stacks, int argc, const char *argv[]);
int			remain_fill(int start, int end, t_list *sorted, t_list *remain);
int			compare(t_stacks *stacks, t_sort *info);
/*
	** using_free
*/
void		free_stacks(t_stacks *stacks);
/*
	** checks
*/
int			*check_param(const char *str);
int			duplicate_check(t_list **list, int num);
int			check_order_end(char name, int value, int push_d);
int			check_sorted(t_list *stack, int size);
void		edge_check(t_stacks *stacks);

/*
	** utils
*/
int			check_stacks(t_stacks *stacks, char num);
void		size_add(t_stacks *stacks, char num);
void		size_minus(t_stacks *stacks, char num);
void		swap_content(void **data1, void **data2);
int			peek(t_list *stack);
char		opposite(char c);
/*
	** sort
*/
int			merge_sort(t_stacks *stacks, int idx_l, int idx_r);
/*
	** math
*/
int			ft_sqrt(unsigned int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
/*
	** common
*/
void		print_inst(char *instruction, char name);
/*
	no_push_sort
*/
void		no_push_sort(t_stacks *stacks, t_sort *info);
/*
	** test_funcs
*/
void		test(t_stacks *stacks);
void		print_li(void *content);
void		print_stack(t_stacks *stacks);

# endif