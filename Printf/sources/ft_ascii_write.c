/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:29:24 by taesan            #+#    #+#             */
/*   Updated: 2020/12/26 17:27:34 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

void		ft_ascii_write(int n)
{
	if (g_info->width != -1)
	{
		if (g_info->flag == '-')
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
