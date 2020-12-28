/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width_pre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:58:37 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 17:24:30 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			width_precision_set(int n, int type)
{
	if (type == 1)
		g_info->width = n;
	else
		g_info->precision_len = n;
}

int				mvidx_rtn_minus(const char *format)
{
	int is_minus;

	is_minus = 0;
	if (format[g_i] == '-')
	{
		g_i++;
		is_minus = 1;
	}
	while (format[g_i] && ft_isdigit(format[g_i]))
		g_i++;
	if (format[g_i] && format[g_i] == '-')
	{
		g_i++;
		is_minus = 1;
	}
	return (is_minus);
}

int				check_star(int type)
{
	int n;

	n = va_arg(*(g_info->ap), int);
	g_i++;
	if (n < 0)
	{
		if (type == 1)
		{
			g_info->flags->minus = 1;
			// g_info->flags->zero = 1;
			n *= -1;
		}
	}
	width_precision_set(n, type);
	return (1);
}

int				check_size(const char *format, int type)
{
	int		start;
	char	*num;
	int		len;

	if (format[g_i] == '*')
		return (check_star(type));
	start = g_i;
	if (mvidx_rtn_minus(format))
	{
		start++;
		if (type == 1)
			g_info->flags->minus = 1;
	}
	if (start != g_i)
	{
		len = g_i - start;
		if (!(num = ft_substr(format, start, len)))
			return (0);
		width_precision_set(ft_atoi(num), type);
		free(num);
	}
	return (1);
}
