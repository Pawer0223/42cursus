/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:50:20 by taesan            #+#    #+#             */
/*   Updated: 2020/12/25 21:43:10 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			remove_zero(t_input *input)
{
	int		i;
	int		j;
	char	*str;

	str = input->str;
	i = 2;
	while (str[i] && str[i] == '0')
		i++;
	if (i > 2)
	{
		j = 2;
		while (str[i])
			str[j++] = str[i++];
		str[j] = 0;
		input->len = ft_strlen(str);
	}
}

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

	len = 2;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
	if (g_info->precision_len > len)
		len = g_info->precision_len + 2;
	input->len = len;
	return (len);
}

int				set_p_zero(t_input *input)
{
	char	*str;
	int		size;

	size = (g_info->precision_len == 0) ? 3 : 4;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (0);
	ft_strlcpy(str, "0x0", size);
	input->len = size - 1;
	input->str = str;
	return (1);
}

int				set_p_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	if (n == 0)
		return (set_p_zero(input));
	size = setlen_p(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	fill_str_p(input, n, size);
	// remove_zero(input);
	return (1);
}
