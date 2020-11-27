/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:55:57 by taekang           #+#    #+#             */
/*   Updated: 2020/11/23 17:56:03 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// remove !!!!
#include <stdio.h>

typedef struct	s_printf
{
	va_list	*ap;
	char	*length;
	char	*input;
	char	flag;
	char	sign_exist;
	char	specifier;
	int		width;
	int		precision_len;
}				t_printf;

t_printf 		*g_info;
int				g_i;
/* global funcs */
int				init_g(va_list *ap);
void			clear_g(void);
void			free_g(void);
/* check funcs */
int				check_flag(const char c);
int				check_size(const char* format, int type);
int				check_len(const char* format);
int				check_spec(const char* format);

/* remove !!! for Test .. */
void			struct_print();
#endif