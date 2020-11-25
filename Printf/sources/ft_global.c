/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:02:52 by taekang           #+#    #+#             */
/*   Updated: 2020/11/08 19:45:16 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		init_g(va_list *ap)
{
	if (!(g_info = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	g_info->ap = ap;
	g_info->flag = 0;
	g_info->length = 0;
	g_info->width = -1;
	g_info->precision_len = -1;
	g_i = 0;
	return (1);
}
void	clear_g()
{
	free(g_info->length);
	g_info->flag = 0;
	g_info->length = 0;
	g_info->width = -1;
	g_info->precision_len = -1;
}
void	free_g(void)
{
	free(g_info->length);
	va_end(*g_info->ap);
	free(g_info);
}
