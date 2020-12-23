/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:47:47 by taesan            #+#    #+#             */
/*   Updated: 2020/12/23 19:48:55 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void		set_f_sign(t_input *input, double n)
{
	int	sign;

	sign = n < 0 ? 1 : 0;
	if (sign == 1)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
	if (g_info->precision_len == -1)
		g_info->precision_len = 6;
}

int			fill_str_f(t_input *input, double n, int len, int idx)
{
	double	expo;
	char	*str;
	int		num;
	char	is_left;

	str = input->str;
	is_left = (idx == 0) ? 1 : 0;
	if (is_left && input->sign)
		str[idx++] = input->sign;
	len--;
	while (len >= 0)
	{
		expo = ft_pow(10, len--);
		num = (int)(n / expo);
		num = num < 0 ? num * -1 : num;
		str[idx++] = num + '0';
		n -= ((int)(n / expo) * expo);
	}
	if (is_left)
		str[idx++] = '.';
	str[idx] = 0;
	return (idx);
}

int			make_floating(t_input *input, double n, double l, double r)
{
	char	*str;
	int		i;
	int		left_len;
	int		right_len;

	left_len = get_left_size(n);
	left_len = left_len == 0 ? 1 : left_len;
	right_len = g_info->precision_len + 1;
	if (!(str = (char*)malloc(sizeof(char) * left_len + right_len + 10)))
		return (0);
	ft_bzero(str, left_len + right_len + 10);
	input->str = str;
	i = fill_str_f(input, l, left_len, 0);
	i = fill_str_f(input, (r * ft_pow(10, right_len)), right_len, i);
	ft_round(str, i - 1, g_info->precision_len, r);
	input->len = ft_strlen(str);
	return (1);
}

int			set_f_input(double n)
{
	t_input	*input;
	double	left;
	double	right;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	set_f_sign(input, n);
	left = get_number(n, 0);
	right = n - left;
	return (make_floating(input, n, left, right));
}
