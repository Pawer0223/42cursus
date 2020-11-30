/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:35:48 by taekang           #+#    #+#             */
/*   Updated: 2020/11/23 19:07:11 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			is_percent(char c)
{
	if (c == '%')
	{
		write(1, &c, 1);
		g_i++;
		return (1);
	}
	return (0);
}

int			ft_printf(const char* format, ...)
{
	va_list 		ap;

	// printf("### input format is : [%s] ### \n", format);
	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			if (!is_percent(format[++g_i]))
			{
				if (!check_format(format) || !ft_set_input_filter(g_info -> specifier))
				{
					free_g();
					return (0);
				}
				ft_format_write(g_info->flag);
				//all_print();
				clear_g();
			}
		}
		else
		{
			write(1, format + g_i, 1);
			g_i++;
		}
	}
	free_g();
}
