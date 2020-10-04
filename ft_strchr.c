/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 04:02:04 by taekang           #+#    #+#             */
/*   Updated: 2020/10/05 04:46:00 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *result;

	result = (char *)s;
	while (*result != c)
	{
		if (!*result)
			return (0);
		result++;
	}
	return (result);
}
