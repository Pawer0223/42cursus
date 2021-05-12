/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:43:00 by taesan            #+#    #+#             */
/*   Updated: 2021/05/12 18:56:38 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "error.h"
# include <limits.h>
# include <stdio.h> // remove !

/*
	** error
*/
int		error_occur(t_list **list);
void	delete_content(void *content);
/*
	** using_malloc
*/
int		*make_num(long long num);
int		make_list(t_list **list, int argc, const char *argv[]);

/*
	** checks
*/
int		*check_param(const char *str);
/*
	** test_funcs
*/
void	print_list(void *content);

# endif