/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:58:53 by taesan            #+#    #+#             */
/*   Updated: 2020/12/23 19:08:46 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			check_flag(const char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		g_info->flag = c;
		g_i++;
	}
}

int				check_size(const char *format, int type)
{
	int		start;
	char	*num;
	size_t	len;

	start = g_i;
	while (format[g_i] && ft_isdigit(format[g_i]))
		g_i++;
	if (start != g_i)
	{
		len = (size_t)(g_i - start);
		if (!(num = ft_substr(format, (unsigned int)start, len)))
			return (0);
		else
		{
			if (type == 1)
				g_info->width = ft_atoi(num);
			else
				g_info->precision_len = ft_atoi(num);
		}
		free(num);
	}
	return (1);
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
		|| c == 'g' || c == 'e')
	{
		g_info->specifier = c;
		g_i++;
		return (1);
	}
	return (0);
}

int				check_format(const char *format)
{
	check_flag(format[g_i]);
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
