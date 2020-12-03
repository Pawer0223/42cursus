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
#include <wchar.h>
// remove !!!!
#include <stdio.h>

typedef struct s_input
{
	char	*str;
	char	sign;
	int		len;
}				t_input;
typedef struct	s_printf
{
	va_list	*ap;
	t_input	*input;
	char	*length;
	char	flag;
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
void			free_input(t_input	*input);
/* check funcs */
int				check_format(const char	*format);
/* set_input_filter */
int				ft_set_input_filter(char spec);
/* set input caller funcs */
int				ft_set_di(char	*length);
int				ft_set_ux(char	*length, char spec);
int				ft_set_c(char	*length);
int				ft_set_s(char	*length);
/* set input funcs */
int				set_di_input(long long n);
int				set_u_input(unsigned long long n);
int				set_x_input(unsigned long long n);
int				set_ascii_input(int n);
int				set_str_input(char *input_str);
/* format write*/
void			ft_format_write(char flag);
/* common */
void			fill_is_zero(t_input* input, int idx);
/* remove !!! for Test .. */
void			all_print();
void			t_printf_print();
void			t_input_print();
#endif