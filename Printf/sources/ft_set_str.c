/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:53:08 by taesan            #+#    #+#             */
/*   Updated: 2020/12/24 03:04:25 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

int				set_str_zero(t_input *input)
{
	char	*str;

	str = 0;
	if (g_info->precision_len == -1)
	{
		if (!(str = (char*)malloc(sizeof(char) * 7)))
			return (0);
		ft_strlcpy(str, "(null)", 7);
		input->len = 6;
	}
	else
		input->len = 0;
	input->str = str;
	return (1);
}

int				set_str_input(char *input_str)
{
	t_input	*input;
	char	*str;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	if (!input_str)
		return (set_str_zero(input));
	if (g_info->precision_len != -1)
		str = ft_substr(input_str, 0, g_info->precision_len);
	else
		str = ft_strdup(input_str);
	if (!str)
		return (0);
	input->len = ft_strlen(str);
	input->str = str;
	return (1);
}
