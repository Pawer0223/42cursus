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

void			fill_str(char *str, long long n, int idx)
{
	long long nmg;

	if (n != 0)
	{
		fill_str(str, (n / 10), (idx - 1));
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		str[idx] = ('0' + nmg);
	}
}

void			set_input_sign(t_input *input, long long n)
{
	if (g_info->specifier == ' ' || g_info->specifier == '+')
		input->sign = g_info->specifier;
	else if (n < 0)
		input->sign = '-';
	else
		input->sign = 0;
}

int				get_num_len(t_input *input, long long n)
{
	int	len;

	len = (n <= 0 || input->sign) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int				set_input(long long n)
{
	t_input		*input;
	char		*str;
	int			len;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	set_input_sign(input, n);
	len = get_num_len(input, n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	input->len = len;
	str[0] = input->sign;
	str[len] = 0;
	fill_str(str, n , len - 1);
	input->str = str;
	g_info->input = input;
	return (1);
}

int				ft_write_di()
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
	if (!set_input(n))
		return (0);
}