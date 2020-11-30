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

void			fill_str2(char* str, long long n, int idx, char sign)
{
	long long nmg;

	if (n != 0)
	{
		fill_str2(str, (n / 10), (idx - 1), sign);
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

void			set_ux_sign(t_input* input, unsigned long long n)
{
	if (n < 0)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
}

int				setlen_retsize2(t_input* input, long long n)
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

int				set_ux_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	set_ux_sign(input, n);
	size = setlen_retsize(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = 0;
	fill_str(str, n, size - 1, input->sign);
	input->str = str;
	g_info->input = input;
	return (1);
}

int				ft_set_ux(char	*length)
{
	unsigned long long	n;

	n = 0;
	if (length)
	{
		if (ft_strncmp(length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long int);
		else if (ft_strncmp(length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long long int);
		else if (ft_strncmp(length, "h", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned short int);
		else if (ft_strncmp(length, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned char);
	}
	else
		n = va_arg(*(g_info->ap), unsigned int);
	if (!set_ux_input(n))
		return (0);
	return (1);
}