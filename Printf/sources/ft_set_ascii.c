/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:29:24 by taesan            #+#    #+#             */
/*   Updated: 2020/12/26 16:43:17 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int				set_ascii_input(char n)
{
	t_input	*input;
	char	*str;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	input->len = 1;
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	input->str = str;
	str[1] = 0;
	str[0] = (char)n;
	return (1);
}
