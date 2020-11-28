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

void	write_padding(char padding, int end)
{
	int i;
	i = 0;
	//printf("end is .. [%d]\n", end);
	while (i < end)
	{
		write(1, &padding, 1);
		i++;
	}
}

void		ft_format_write(char flag)
{
	int		end;
	char	padding;
	t_input	*input;
	
	padding= ' ';
	// 0 이면서 , 정밀도가 없을 때 padding 0으로채우기
	if (flag == '0' && g_info->precision_len == -1)
		padding = '0';
	input = g_info->input;
	end = (g_info->width - input->len);
	if (flag == '-')
	{
		ft_putstr_fd(input->str, 1);
		write_padding(' ', end);
	}
	else
	{
		write_padding(padding, end);
		ft_putstr_fd(input->str, 1);
	}
}

int		set_input(char spec)
{
	if (spec == 'd' || spec == 'i')
		ft_set_di();
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
	if (format[++g_i] && !check_flag(format[g_i]))
		return (1);
	if (!format[g_i] || !check_size(format, 1))
		return (0);
	if (format[g_i] == '.')
	{
		g_info->precision_len = 0;
		g_i++;
		if (!check_size(format, 2))
			return (0);
	}
	if (!format[g_i] || !check_len(format))
		return (0);
	if (!format[g_i] || !check_spec(format[g_i]))
		return (0);
	if (!set_input(g_info->specifier))
		return (0);
	ft_format_write(g_info->flag);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list 		ap;

	// printf("### input format is : [%s] ### \n", format);
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
			// all_print();
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
