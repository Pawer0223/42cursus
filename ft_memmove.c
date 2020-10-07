/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:15:56 by taekang           #+#    #+#             */
/*   Updated: 2020/10/07 17:42:06 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_dst;
	const char	*str_src;
	size_t		i;

	str_dst = dst;
	str_src = src;
	i = 0;
	if (dst <= src)
	{
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			str_dst[(len - 1)] = str_src[(len - 1)];
			len--;
		}
	}
	return (str_dst);
}
