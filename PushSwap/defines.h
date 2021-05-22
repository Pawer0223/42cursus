/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:12:48 by taekang           #+#    #+#             */
/*   Updated: 2021/05/22 13:33:19 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft/libft.h"
/*
	**  pa, pb에서 a, b를 구분하기 위함
	**  이거 처음에 push_swap.h에 두니깐.. push_swap.h에서 stack_funcs.h include할 때 에러남..
*/
typedef	struct	s_stacks
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
}				t_stacks;

/*
	errors
*/
# define ERROR "Error"
# define STACK_N "Stacks is NULL"
# define STACK_NM_ERROR "Stack Name Error"
/*

*/
# define A 'A'
# define B 'B'
# define ALL 'Z'

#endif
