/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:18:36 by taesan            #+#    #+#             */
/*   Updated: 2020/12/28 02:10:48 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int			get_left_size(double d)
{
	int left_size;

	if (d < 0)
		d *= -1;
	left_size = 0;
	while (d >= 1)
	{
		d /= 10;
		left_size++;
	}
	return (left_size);
}

double		get_number(double d, int need_last)
{
	double	left;
	int		expo;
	int		last;

	expo = get_left_size(d);
	expo = expo == 0 ? 1 : expo;
	d *= ft_pow(10, (expo * -1));
	left = 0;
	last = 0;
	while (expo > 0)
	{
		d *= 10;
		left += (int)d * ft_pow(10, --expo);
		last = (int)d;
		d -= (int)d;
	}
	if (need_last)
		return (last);
	return (left);
}
