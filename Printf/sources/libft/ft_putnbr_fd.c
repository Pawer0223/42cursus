/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:43:34 by taekang           #+#    #+#             */
/*   Updated: 2020/10/19 14:47:33 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num >= 0 && num < 10)
		ft_putchar_fd('0' + num, fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd('0' + num % 10, fd);
	}
}
