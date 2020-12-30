/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:28:16 by taesan            #+#    #+#             */
/*   Updated: 2020/12/30 23:38:02 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

int			format_write_start(const char *format)
{
	g_i++;
	if (!check_format(format) || !ft_set_input_filter(g_info->specifier))
	{
		free_g();
		return (0);
	}
	if (g_info->specifier != 'n' && g_info->specifier != 'c')
	{
		if (g_info->specifier == '%')
			percent_write(g_info->flags);
		else
		{
			if (g_info->width < 0)
				g_info->width *= -1;
			ft_format_write(g_info->flags);
		}
	}
	clear_g();
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			if (!format_write_start(format))
				return (0);
		}
		else
		{
			ft_putchar_fd(format[g_i], 1);
			g_i++;
			g_w_cnt++;
		}
	}
	free_g();
	return (g_w_cnt);
}
