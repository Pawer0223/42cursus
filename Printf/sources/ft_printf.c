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
#include "libft.h"

int		write_format(char spec)
{
	if (spec == 'd' || spec == 'i')
		ft_write_di();
	//else if (c == 'u' || c == 'x' || c == 'x')
	//	write_di(format);
	//else if (c == 'c')
	//	write_di(format);
	//else if (c == 's')
	//	write_di(format);
	//else if (c == 'p')
	//	write_di(format);
	//else if (c == 'n')
	//	write_di(format);
	//else if (c == 'f' || c == 'g' || c == 'e')
	//	write_di(format);
	return (1);
}
/* input format_check */
int		check_format(const char *format)
{
	if (format[++g_i] && check_flag(format[g_i]))
		g_i++;
	if (!format[g_i] || !check_size(format, 1))
		return (0);
	if (format[g_i] == '.')
	{
		g_i++;
		if (check_size(format, 2))
			return (0);
	}
	if (!format[g_i] || !check_len(format))
		return (0);
	if (!format[g_i] || !check_spec(format[g_i]))
		return (0);
	if (!write_format(g_info->specifier))
		return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list 		ap;

	printf("### input format is : [%s] ### \n", format);
	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			if (!check_format(format))
			{
				free_g();
				return (0);
			}
			all_print();
			clear_g();
		}
		else
		{
			write(1, format + g_i, 1);
			g_i++;
		}
	}
	free_g();
}
