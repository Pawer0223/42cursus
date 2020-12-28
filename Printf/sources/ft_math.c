/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:21:47 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 17:05:33 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

double		ft_pow(double base, double exponent)
{
	double	result;
	int		i;

	if ((int)exponent == 0)
		return (1);
	result = 1;
	i = 0;
	if (exponent < 0)
	{
		i = exponent;
		while (i++ < 0)
			result /= base;
	}
	else
	{
		while (i++ < exponent)
			result *= base;
	}
	return (result);
}

int			check_signif(double n)
{
	int		limit;
	int		i;
	double	temp;

	limit = 16;
	i = 0;
	while (i < limit)
	{
		temp = n * ft_pow(2, i);
		if (temp < 0)
			temp *= -1;
		if (temp == 1)
			return (1);
		i++;
	}
	return (0);
}

void		round_up(char *str, int idx, int len)
{
	int prev;

	if (str[idx] == '.')
		idx--;
	prev = str[idx] - '0' + 1;
	if (g_info->precision_len == 0)
	{
		str[0] = (prev / 10) + '0';
		str[1] = (prev % 10) + '0';
		str[2] = 0;
		return ;
	}
	str[idx--] = (prev % 10) + '0';
	if (idx == 0)
		str[idx] = (prev / 10) + '0';
	if ((prev / 10) > 0)
		round_up(str, idx, len);
}

void		ft_round(char *str, int idx, int pre, double n)
{
	int last;
	int prev;

	last = str[idx--] - '0';
	prev = pre == 0 ? str[--idx] - '0' : str[idx] - '0';
	str[idx + 1] = 0;
	if (last >= 5)
	{
		if (last == 5 && (prev % 2 == 0) && check_signif(n))
			str[++idx] = 0;
		else
		{
			if ((prev + 1) > 9)
				round_up(str, idx, ft_strlen(str));
			else
				str[idx++] = prev + 1 + '0';
			return ;
		}
	}
}
