/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:18:12 by taesan            #+#    #+#             */
/*   Updated: 2020/12/27 19:10:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int			init_g(va_list *ap)
{
	if (!(g_info = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	g_info->ap = ap;
	g_info->flag = 0;
	g_info->flag_zero = 0;
	g_info->length = 0;
	g_info->input = 0;
	g_info->width = 0;
	g_info->precision_len = -1;
	g_info->input = 0;
	g_i = 0;
	g_w_cnt = 0;
	return (1);
}

void		clear_g(void)
{
	if (g_info->length)
		free(g_info->length);
	if (g_info->input)
		free_input(g_info->input);
	g_info->length = 0;
	g_info->input = 0;
	g_info->flag = 0;
	g_info->flag_zero = 0;
	g_info->width = 0;
	g_info->precision_len = -1;
}

void		free_input(t_input *input)
{
	if (input->str)
		free(input->str);
	free(input);
}

void		free_g(void)
{
	if (g_info->length)
		free(g_info->length);
	if (g_info->input)
		free_input(g_info->input);
	va_end(*g_info->ap);
	free(g_info);
}
