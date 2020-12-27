/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:30:02 by taesan            #+#    #+#             */
/*   Updated: 2020/12/27 15:44:22 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

int				ft_set_di(char *length)
{
	long long	n;

	n = 0;
	if (length)
	{
		if (ft_strncmp(length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), long int);
		else if (ft_strncmp(length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), long long int);
		else
			n = va_arg(*(g_info->ap), int);
	}
	else
		n = va_arg(*(g_info->ap), int);
	return (set_di_input(n));
}

int				ft_set_ux(char *length, char spec)
{
	unsigned long long	n;

	n = 0;
	if (length)
	{
		if (ft_strncmp(length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long int);
		else if (ft_strncmp(length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long long int);
		else
			n = va_arg(*(g_info->ap), unsigned int);
	}
	else
		n = va_arg(*(g_info->ap), unsigned int);
	if (spec == 'u')
		return (set_u_input(n));
	else
		return (set_x_input(n));
}

int				ft_set_s(void)
{
	char	*str;

	str = va_arg(*(g_info->ap), char *);
	return (set_str_input(str));
}

int				ft_set_p(void)
{
	unsigned long long n;

	n = (unsigned long long)va_arg(*(g_info->ap), void *);
	return (set_p_input(n));
}
