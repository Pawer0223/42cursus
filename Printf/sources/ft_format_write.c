/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:09:00 by taesan            #+#    #+#             */
/*   Updated: 2020/12/29 21:39:04 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void		write_padding(char padding, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		ft_putchar_fd(padding, 1);
		g_w_cnt++;
		i++;
	}
}

char		get_padding(t_flag *flags)
{
	char padding;

	padding = ' ';
	if (flags->zero && !flags->minus)
	{
		if (g_info->precision_len < 0 || g_info->specifier == 'f')
			padding = '0';
	}
	return (padding);
}

void		percent_write(t_flag *flags)
{
	int		width;
	char	padding;

	width = g_info->width;
	padding = get_padding(flags);
	if (flags->minus)
	{
		ft_putchar_fd('%', 1);
		write_padding(padding, width - 1);
	}
	else
	{
		write_padding(padding, width - 1);
		ft_putchar_fd('%', 1);
	}
	g_w_cnt++;
}

void		write_with_sign(int end, char padding)
{
	t_input	*input;
	char	*str;

	input = g_info->input;
	str = input->str;
	if (input->sign)
	{
		if (g_info->flags->zero && g_info->precision_len < 0)
			ft_putchar_fd(input->sign, 1);
		else if (g_info->flags->zero && g_info->specifier == 'f')
			ft_putchar_fd(input->sign, 1);
		else
		{
			write_padding(padding, end);
			ft_putchar_fd(input->sign, 1);
			ft_putstr_fd(str, 1);
			return ;
		}
	}
	write_padding(padding, end);
	ft_putstr_fd(str, 1);
}

void		ft_format_write(t_flag *flags)
{
	int		end;
	char	padding;
	t_input	*input;

	padding = get_padding(flags);
	input = g_info->input;
	if (!input->str)
		return ;
	end = (g_info->width - input->len);
	if (input->sign)
	{
		end--;
		g_w_cnt++;
	}
	if (flags->minus)
	{
		if (input->sign)
			ft_putchar_fd(input->sign, 1);
		ft_putstr_fd(input->str, 1);
		write_padding(' ', end);
	}
	else
		write_with_sign(end, padding);
	g_w_cnt += ft_strlen(input->str);
}
