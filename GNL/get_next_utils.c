/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:19:05 by taesan            #+#    #+#             */
/*   Updated: 2021/01/04 14:29:47 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*content_null(char *buf, char *content)
{
	char *new_content;

	if (!(new_content = ft_strdup(buf)))
		return (0);
	free(buf);
	return (new_content);
}

int			ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
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

char		*ft_substr(char *s, unsigned int start, size_t len)
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
