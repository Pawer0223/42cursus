/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 12:04:00 by taekang           #+#    #+#             */
/*   Updated: 2020/10/11 13:46:10 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;

	src = (char *)s;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
	{
		return (0);
	}
	ft_strlcpy(dst, (s + start), len + 1);
	return (dst);
}
