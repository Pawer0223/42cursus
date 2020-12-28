/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:50:20 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 19:50:00 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			fill_str_p(t_input *input, unsigned long long n, int idx)
{
	int		nmg;

	input->str[0] = '0';
	input->str[1] = 'x';
	while (n != 0)
	{
		nmg = n % 16;
		if (nmg >= 10)
			nmg = 'a' + (nmg % 10);
		else
			nmg = '0' + nmg;
		input->str[idx--] = nmg;
		n /= 16;
	}
	while (idx >= 2)
		input->str[idx--] = '0';
}

int				setlen_p(t_input *input, unsigned long long n)
{
	int	len;

	len = (n == 0 && g_info->precision_len < 0) ? 3 : 2;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if (g_info->precision_len > len)
		len = g_info->precision_len + 2;
	if (g_info->precision_len < 0 && g_info->flags->zero)
		len = g_info->width > len ? g_info->width : len;
	input->len = len;
	return (len);
}

int				set_p_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	set_input_sign(input);
	size = setlen_p(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	fill_str_p(input, n, size);
	return (1);
}
