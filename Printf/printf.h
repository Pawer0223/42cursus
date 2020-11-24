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

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// remove !!!!
#include <stdio.h>

typedef struct	s_printf
{
	va_list	*ap;
	char	*length;
	char	flag;
	char	specifier;
	int		width;
	int		precision_len;
}				t_printf;
t_printf 		*g_info;
int				g_i;
void			start(const char *format, ...);
int				init_g(va_list *ap);
void			clear_g(void);
void			free_g(void);
