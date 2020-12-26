/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_input_filter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:49:13 by taesan            #+#    #+#             */
/*   Updated: 2020/12/26 17:17:55 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		ft_set_input_filter(char spec)
{
	if (spec == 'd' || spec == 'i')
		return (ft_set_di(g_info->length));
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		return (ft_set_ux(g_info->length, spec));
	else if (spec == 'c')
		ft_ascii_write(va_arg(*(g_info->ap), int));
	else if (spec == 's')
		return (ft_set_s(g_info->length));
	else if (spec == 'p')
		return (ft_set_p());
	else if (spec == 'n')
		ft_set_n(g_info->length);
	else if (spec == 'f' || spec == 'g' || spec == 'e')
		return (ft_set_fge());
	return (1);
}
