/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:11:12 by taekang           #+#    #+#             */
/*   Updated: 2020/10/01 20:45:26 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > dest_len + 1)
	{
		while (src[i] != '\0' && dest_len + 1 + i < dstsize)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
		return (dest_len + i);
	}
	else
	{
		return (dstsize + src_len);
	}
}
