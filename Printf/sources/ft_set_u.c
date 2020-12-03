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

void			fill_str_u(t_input* input, long long n, int idx)
{
	if (n == 0)
		fill_is_zero(input, idx--);
	while (idx >= 0 && n != 0)
	{
		input->str[idx--] = '0' + (n % 10);
		n /= 10;
	}
	while (idx >= 0)
		input->str[idx--] = '0';
}

int				setlen_u(t_input* input, unsigned long long n)
{
	int	len;

	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if ((g_info->precision_len) > len)
		len = g_info->precision_len;
	input->len = len;
	return (len);
}

int				set_u_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	size = setlen_u(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	fill_str_u(input, n, size);
	return (1);
}