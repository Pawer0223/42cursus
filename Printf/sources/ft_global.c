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

#include "../headers/printf.h"

int		init_g(va_list *ap)
{
	if (!(g_info = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	g_info->ap = ap;
	g_info->flag = 0;
	g_info->length = 0;
	g_info->input = 0;
	g_info->width = -1;
	g_info->precision_len = -1;
	g_info->input = 0;
	g_i = 0;
	g_w_cnt = 0;
	return (1);
}
void	clear_g()
{
	if (g_info->length)
		free(g_info->length);
	if (g_info->input)
		free_input(g_info->input);
	g_info->length = 0;
	g_info->input = 0;
	g_info->flag = 0;
	g_info->width = -1;
	g_info->precision_len = -1;
}

void	free_input(t_input	*input)
{
	if (input->str)
		free(input->str);
	free(input);
}
void	free_g(void)
{
	if (g_info->length)
		free(g_info->length);
	if (g_info->input)
		free_input(g_info->input);
	va_end(*g_info->ap);
	free(g_info);
}