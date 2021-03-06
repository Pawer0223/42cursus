/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:55:37 by taekang           #+#    #+#             */
/*   Updated: 2020/10/07 11:03:58 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_isalnum(int c)
{
	int isalpha;

	isalpha = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	if (isalpha)
		return (isalpha);
	return ((c >= '0') && (c <= '9'));
}
