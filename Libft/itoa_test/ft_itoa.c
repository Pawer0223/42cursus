/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:17:45 by taekang           #+#    #+#             */
/*   Updated: 2020/10/15 14:20:54 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			get_len(long long n)
{
	int len;

	len = n <= 0 ? 1 : 0;

	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}


char		*ft_itoa(int n)
{
	char		*str;
	long long	num;
	int			len;
	int			start;
	num = n;
	len = get_len(num);

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	start = 0;
	if (num < 0)
	{
		num *= -1;
		str[start] = '-';
		start++;
	}
	while (len >= start)
	{
		str[len] = '0' + (num % 10);
		num /= 10;
		len--;
	}
	return (str);
}

void	ft_call(const char *argv[])
{
	int n = ft_atoi(argv[1]);
	char *result = ft_itoa(n);
	printf("itoa result .. [%s]\n" , result);
}

int		main(int argc, const char *argv[])
{
	ft_call(argv);
	return (0);
}
