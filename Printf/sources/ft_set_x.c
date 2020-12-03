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

void			fill_str_x(t_input *input, unsigned long long n, int idx)
{
	int		end;
	int		nmg;
	char	aA;

	if (n == 0)
		fill_is_zero(input, idx--);
	end = (g_info->flag == '#' && n != 0) ? 2 : 0;
	while (idx >= 0 && n != 0)
	{
		nmg = n % 16;
		if (nmg >= 10)
		{
			aA = (g_info->specifier == 'x') ? 'a' : 'A';
			nmg = aA + (nmg % 10);
		}
		else
			nmg = '0' + nmg;
		input->str[idx--] = nmg;
		n /= 16;
	}
	while (idx >= end)
		input->str[idx--] = '0';
}

int				setlen_x(t_input* input, unsigned long long n)
{
	int					len;
	unsigned long long	org;

	len = (n == 0) ? 1 : 0;
	org = n;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if ((g_info->precision_len) > len)
		len = g_info->precision_len;
	if (g_info->flag == '#' && org != 0)
		len += 2;
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
	if (g_info->flag == '#' && n != 0)
		str[1] = g_info->specifier;
	fill_str_x(input, n, size);
	return (1);
}