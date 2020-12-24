/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:31:34 by taesan            #+#    #+#             */
/*   Updated: 2020/12/25 02:38:49 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			fill_str_di(t_input *input, long long n, int idx)
{
	int		nmg;

	if (n == 0)
		fill_is_zero(input, idx--);
	while (idx >= 0 && n != 0)
	{
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		input->str[idx--] = '0' + nmg;
		n /= 10;
	}
	while (idx >= 0)
		input->str[idx--] = '0';
}

int				setlen_di(t_input *input, long long n)
{
	int	len;

	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (g_info->precision_len > len)
		len = g_info->precision_len;
	input->len = len;
	return (len);
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
	input->str = str;
	str[size--] = 0;
	fill_str_di(input, n, size);
	return (1);
}
