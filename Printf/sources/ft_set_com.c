/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:30:47 by taesan            #+#    #+#             */
/*   Updated: 2020/12/29 17:56:07 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void			fill_is_zero(t_input *input, int idx)
{
	if (g_info->precision_len == 0)
	{
		input->str[idx] = 0;
		input->len = 0;
	}
	else
		input->str[idx] = '0';
}

void			set_input_sign(t_input *input)
{
	if (g_info->flags->space && !g_info->flags->plus)
		input->sign = ' ';
	else if (g_info->flags->plus)
		input->sign = '+';
	else
		input->sign = 0;
}

void			set_double_sign(t_input *input, char *ptr)
{
	int		is_minus;
	int		len;

	len = sizeof(double) - 1;
	is_minus = ((*(ptr + len) >> 7) & 0x01);
	if (is_minus)
		input->sign = '-';
	else
		set_input_sign(input);
	if (g_info->precision_len < 0)
		g_info->precision_len = 6;
}

// int				get_bit(char *ptr, int byte, int bit)
// {
// 	return (*(ptr + byte) >> bit) & 0x01;
// }

// double			read_bit(char *str, int exponent)
// {
// 	int		idx;
// 	int		increase;
// 	double	result;

// 	increase = (exponent < 0) ? -1 : 1;
// 	idx = 0;
// 	result = 0;
// 	while (str[idx])
// 	{
// 		if (str[idx] == '1')
// 			result += ft_pow(2, exponent);
// 		idx++;
// 		exponent += increase;
// 	}
// 	return (result);
// }
