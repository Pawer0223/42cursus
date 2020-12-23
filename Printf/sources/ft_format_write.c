/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:09:00 by taesan            #+#    #+#             */
/*   Updated: 2020/12/24 02:18:32 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void		write_padding(char padding, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		ft_putchar_fd(padding, 1);
		g_w_cnt++;
		i++;
	}
}

void		percent_write(void)
{
	int width;

	width = g_info->width;
	write_padding(' ', width - 1);
	ft_putchar_fd('%', 1);

	if (width == -1)
		width = 1;
	g_w_cnt += width;
}

void		ft_format_write(char flag)
{
	int		end;
	char	padding;
	t_input	*input;

	padding = ' ';
	if (flag == '0' && g_info->precision_len == -1)
		padding = '0';
	input = g_info->input;
	end = (g_info->width - input->len);
	if (flag == '-')
	{
		ft_putstr_fd(input->str, 1);
		write_padding(' ', end);
	}
	else
	{
		write_padding(padding, end);
		ft_putstr_fd(input->str, 1);
	}
	g_w_cnt += ft_strlen(input->str);
}
