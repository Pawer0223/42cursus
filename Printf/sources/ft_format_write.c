/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:35:48 by taekang           #+#    #+#             */
/*   Updated: 2020/11/23 19:07:11 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	write_padding(char padding, int end)
{
	int i;
	i = 0;
	// printf("end is .. [%d]\n", end);
	while (i < end)
	{
		write(1, &padding, 1);
		i++;
	}
}

void		ft_format_write(char flag)
{
	int		end;
	char	padding;
	t_input* input;

	padding = ' ';
	// 0 이면서 , 정밀도가 없을 때 padding 0으로채우기
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
}
