/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:26:18 by taekang           #+#    #+#             */
/*   Updated: 2021/02/24 15:42:51 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*result;
	size_t			i;

	result = s;
	i = 0;
	while (i < n)
		result[i++] = 0;
}
