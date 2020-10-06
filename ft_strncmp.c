/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 07:10:06 by taekang           #+#    #+#             */
/*   Updated: 2020/10/06 07:34:48 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while (i < n)
	{
		result = s1[i] - s2[i];
		if (result < 0 || result > 0)
			return (result);
		if (!s1[i] || !s2[i])
			return (result);
		i++;
	}
	return (result);
}
