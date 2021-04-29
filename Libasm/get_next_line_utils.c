/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:19:05 by taesan            #+#    #+#             */
/*   Updated: 2021/01/05 18:14:10 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*content_null(char *buf)
{
	char *new_content;

	if (!(new_content = ft_strdup(buf)))
		return (0);
	return (new_content);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t i;

	if (!src)
		return (0);
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!dest)
		return (src_len);
	if (dstsize)
	{
		i = 0;
		while (src[i] && i + 1 < dstsize)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char		*ft_substr(char *s, int start, size_t len)
{
	char	*dst;

	if (!s)
		return (0);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= ft_strlen(s))
		ft_strlcpy(dst, "", 2);
	else
		ft_strlcpy(dst, (s + start), len + 1);
	return (dst);
}
