/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width_pre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:58:37 by taesan            #+#    #+#             */
/*   Updated: 2020/12/24 17:58:53 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			width_precision_set(int type, int n)
{
	if (type == 1)
		g_info->width = n;
	else
		g_info->precision_len = n;
}

int				mvidx_rtn_minus(const char *format, int type)
{
	int is_minus;

	is_minus = 0;
	if (format[g_i] == '-')
	{
		g_i++;
		is_minus = 1;
	}
	while (format[g_i] && ft_isdigit(format[g_i]))
		g_i++;
	if (is_minus)
		width_precision_set(type, 0);
	return (is_minus);
}

int				check_size(const char *format, int type)
{
	int		start;
	char	*num;
	size_t	len;
	int		minus;

	start = g_i;
	minus = mvidx_rtn_minus(format, type);
	if (!minus && start != g_i)
	{
		len = (size_t)(g_i - start);
		if (!(num = ft_substr(format, start, len)))
			return (0);
		else
			width_precision_set(ft_atoi(num), type);
		free(num);
	}
	return (1);
}
