/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:29:24 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 16:18:09 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void		ft_ascii_write(int n)
{
	if (g_info->width > 1)
	{
		if (g_info->flags->minus)
		{
			ft_putchar_fd(n, 1);
			write_padding(' ', g_info->width - 1);
		}
		else
		{
			write_padding(' ', g_info->width - 1);
			ft_putchar_fd(n, 1);
		}
	}
	else
		ft_putchar_fd(n, 1);
	g_w_cnt++;
}
