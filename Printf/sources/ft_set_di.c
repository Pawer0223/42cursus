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

void			fill_str(char *str, long long n, int idx, char sign)
{
	long long nmg;

	if (n != 0)
	{
		fill_str(str, (n / 10), (idx - 1), sign);
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		str[idx] = ('0' + nmg);
	}
	else
	{
		if (sign && idx >= 0)
			str[idx--] = sign;
		while (idx >= 0)
			str[idx--] = '0';
	}
}

void			set_input_sign(t_input *input, long long n)
{
	if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else if (n < 0)
		input->sign = '-';
	else
		input->sign = 0;
}

int				setlen_retsize(t_input *input, long long n)
{
	int	len;
	
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	input->len = len;
	if (n <= 0 || input->sign)
		len++;
	if (g_info->precision_len > len)
		return (g_info->precision_len);
	return (len);
}

int				set_num_input(long long n)
{
	t_input		*input;
	char		*str;
	int			size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	set_input_sign(input, n);
	size = setlen_retsize(input, n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = 0;
	fill_str(str, n , size - 1, input->sign);
	input->str = str;
	g_info->input = input;
	return (1);
}

int				ft_set_di()
{
	long long	n;

	n = 0;
	if (g_info->length)
	{
		if (ft_strncmp(g_info->length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), long int);
		else if (ft_strncmp(g_info->length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), long long int);
		else if (ft_strncmp(g_info->length, "h", 3) == 0)
			n = va_arg(*(g_info->ap), short int);
		else if (ft_strncmp(g_info->length, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), signed char);
	}
	else
		n = va_arg(*(g_info->ap), int);
	if (!set_num_input(n))
		return (0);
	return (1);
}