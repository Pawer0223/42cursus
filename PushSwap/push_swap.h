/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 15:31:52 by taesan           ###   ########.fr       */
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
	int		sorted_size;
	int		data_size;
	char	data_nm;
	char	sorted_nm;
	t_list	*data;
	t_list	*sorted;
}				t_sort;

typedef	struct	s_stacks
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
	int		tree_level;
}				t_stacks;
/*
	** stack funcs
*/
void	push(t_stacks *stacks, char name);
void	rotate(t_stacks *stacks, char name, int is_reverse);
void	loop_rotate(t_stacks *stacks, char name, int cnt, int is_reverse);
void	swap(t_stacks *s, char name);
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

/*
	** utils
*/
int		check_stacks(t_stacks *stacks, char num);
void	size_add(t_stacks *stacks, char num);
void	size_minus(t_stacks *stacks, char num);
void	swap_content(void **data1, void **data2);
int		peek(t_list *stack);
char	opposite(char c);
/*
	** sort
*/
int		merge_sort(t_stacks *stacks, int idx_l, int idx_r);

/*
	** test_funcs
*/
void		test(t_stacks *stacks);
void		print_li(void *content);
void		print_stack(t_stacks *stacks);

/*
	** math
*/
int			ft_sqrt(unsigned int n);
int			ft_min(int a, int b);

/*
	** common
*/
void		print_inst(char *instruction, char name);




# endif