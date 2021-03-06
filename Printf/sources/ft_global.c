/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:18:12 by taesan            #+#    #+#             */
/*   Updated: 2020/12/29 19:32:47 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void			init_flags(void)
{
	g_info->flags->plus = 0;
	g_info->flags->minus = 0;
	g_info->flags->space = 0;
	g_info->flags->hash = 0;
	g_info->flags->zero = 0;
}

int				init_g(va_list *ap)
{
	if (!(g_info = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	if (!(g_info->flags = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	init_flags();
	g_info->ap = ap;
	g_info->length = 0;
	g_info->input = 0;
	g_info->width = 0;
	g_info->precision_len = -1;
	g_info->input = 0;
	g_i = 0;
	g_w_cnt = 0;
	return (1);
}

void			free_with_clear(t_input *input)
{
	if (g_info->input)
	{
		input->sign = 0;
		input->len = 0;
		if (input->str)
			free(input->str);
		free(input);
	}
	if (g_info->length)
		free(g_info->length);
}

void			clear_g(void)
{
	free_with_clear(g_info->input);
	init_flags();
	g_info->length = 0;
	g_info->input = 0;
	g_info->width = 0;
	g_info->precision_len = -1;
}

void			free_g(void)
{
	clear_g();
	if (g_info->flags)
		free(g_info->flags);
	va_end(*g_info->ap);
	free(g_info);
}
