/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:58:53 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 17:01:19 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			check_flag(const char *format)
{
	char c;

	c = format[g_i];
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		if (!g_info->flags->exist)
			g_info->flags->exist = 1;
		if (c == '-')
			g_info->flags->minus = 1;
		if (c == '+')
			g_info->flags->plus = 1;
		if (c == '#')
			g_info->flags->hash = 1;
		if (c == '0')
			g_info->flags->zero = 1;
		if (c == ' ')
			g_info->flags->space = 1;
		g_i++;
		check_flag(format);
	}
	return ;
}

int				check_len(const char *format)
{
	char	*len;
	int		seq;

	seq = 0;
	if (format[g_i] == 'l' || format[g_i] == 'h')
	{
		if (!(len = (char*)malloc(sizeof(char) * 3)))
			return (0);
		len[seq++] = format[g_i++];
		if (format[g_i] == len[0])
			len[seq++] = format[g_i++];
		len[seq] = 0;
		g_info->length = len;
	}
	return (1);
}

int				check_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'n' || c == 'f'
		|| c == 'g' || c == 'e' || c == '%')
	{
		g_info->specifier = c;
		g_i++;
		return (1);
	}
	return (0);
}

int				check_format(const char *format)
{
	check_flag(format);
	if (!format[g_i] || !check_size(format, 1))
		return (0);
	if (format[g_i] == '.')
	{
		g_info->precision_len = 0;
		if (!format[++g_i] || !check_size(format, 2))
			return (0);
	}
	if (!format[g_i] || !check_len(format))
		return (0);
	if (!format[g_i] || !check_spec(format[g_i]))
		return (0);
	return (1);
}
