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

void			fill_str_di(char *str, long long n, int idx, char sign)
{
	long long nmg;

	if (n != 0)
	{
		fill_str_di(str, (n / 10), (idx - 1), sign);
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		str[idx] = ('0' + nmg);
		// printf("str[%d]:%c\n", idx ,str[idx]);
	}
	else
	{
		if (sign && idx >= 0)
			str[idx--] = sign;
		while (idx >= 0)
			str[idx--] = '0';
	}
}

void			set_di_sign(t_input *input, long long n)
{
	if (n < 0)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
}

int				setlen_di(t_input *input, long long n)
{
	int	len;
	long long org = n;
	
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (input->sign || org <= 0)
		len++;
	if ((g_info->precision_len) > len)
		len = g_info->precision_len;
	input->len = len;
	return (len);
}

int				set_di_input(long long n)
{
	t_input		*input;
	char		*str;
	int			size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	set_di_sign(input, n);
	size = setlen_di(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = 0;
	fill_str_di(str, n , size - 1, input->sign);
	input->str = str;
	return (1);
}