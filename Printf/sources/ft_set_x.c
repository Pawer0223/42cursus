/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:55:10 by taesan            #+#    #+#             */
/*   Updated: 2020/12/29 04:27:34 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			fill_str_x(t_input *input, unsigned long long n, int idx)
{
	int		end;
	int		nmg;
	char	is_a;

	if (n == 0)
		fill_is_zero(input, idx--);
	end = (g_info->flags->hash && n != 0) ? 2 : 0;
	while (idx >= 0 && n != 0)
	{
		nmg = n % 16;
		if (nmg >= 10)
		{
			is_a = (g_info->specifier == 'x') ? 'a' : 'A';
			nmg = is_a + (nmg % 10);
		}
		else
			nmg = '0' + nmg;
		input->str[idx--] = nmg;
		n /= 16;
	}
	while (idx >= end)
		input->str[idx--] = '0';
}

int				setlen_x(t_input *input, unsigned long long n)
{
	int					len;
	unsigned long long	org;
	t_flag				*flags;

	flags = g_info->flags;
	len = (n == 0) ? 1 : 0;
	org = n;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if ((g_info->precision_len) > len)
		len = g_info->precision_len;
	if (flags->hash && org != 0)
	{
		len += 2;
		if (g_info->precision_len < 0 && flags->zero && !flags->minus)
			len = g_info->width > len ? g_info->width : len;
	}
	input->len = len;
	return (len);
}

int				set_x_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	size = setlen_x(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	str[0] = '0';
	if (g_info->flags->hash && n != 0)
		str[1] = g_info->specifier;
	fill_str_x(input, n, size);
	return (1);
}
