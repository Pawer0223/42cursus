/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:14:28 by taekang           #+#    #+#             */
/*   Updated: 2020/10/11 16:22:02 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len;
	int		set_len;
	int		start;
	int		i;

	len = ft_strlen(s1);
	set_len = ft_strlen(set);
	start = 0;
	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (set_len)
	{
		while (s1[start] && start < len)
		{
			while (ft_strnstr((s1 + start), set, set_len))
				start += set_len;
			result[i] = s1[start];
			i++;
			start++;
		}
	}
	result[i] = '\0';
	return (result);
}
