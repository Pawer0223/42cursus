/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_caller2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:30:57 by taesan            #+#    #+#             */
/*   Updated: 2020/12/30 00:31:23 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void			ft_set_n(char *length)
{
	if (length)
	{
		if (ft_strncmp(length, "h", 3) == 0)
			*va_arg(*(g_info->ap), short int*) = g_w_cnt;
		else if (ft_strncmp(length, "hh", 3) == 0)
			*va_arg(*(g_info->ap), char*) = g_w_cnt;
		else if (ft_strncmp(length, "l", 3) == 0)
			*va_arg(*(g_info->ap), long int*) = g_w_cnt;
		else if (ft_strncmp(length, "ll", 3) == 0)
			*va_arg(*(g_info->ap), long long int *) = g_w_cnt;
	}
	else
		*va_arg(*(g_info->ap), int *) = g_w_cnt;
}

int				ft_set_fge(void)
{
	double	n;

	n = va_arg(*(g_info->ap), double);
	if (g_info->specifier == 'f')
		return (set_f_input(n));
	return (0);
}
