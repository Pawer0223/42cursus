/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:17:45 by taekang           #+#    #+#             */
/*   Updated: 2020/10/15 14:25:51 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_ll_len(long long n)
{
	int len;

	len = n <= 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char* ft_lltoa(long long n)
{
	char		*str;
	int			len;
	int			start;
	int			nmg;

	len = get_ll_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	start = 0;
	if (n < 0)
		str[start++] = '-';
	while (len >= start)
	{
		nmg = n % 10;

		if (nmg < 0)
			nmg *= -1;
		str[len] = '0' + nmg;
		n /= 10;
		len--;
	}
	return (str);
}