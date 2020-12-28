/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:53:08 by taesan            #+#    #+#             */
/*   Updated: 2020/12/29 02:14:27 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

int				set_str_zero(t_input *input)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 7)))
		return (0);
	if (g_info->width > g_info->precision_len && g_info->precision_len < 6)
		str[0] = 0;
	else
	{
		ft_strlcpy(str, "(null)", 7);
		if (g_info->precision_len >= 0)
			str = ft_substr(str, 0, g_info->precision_len);
	}
	input->str = str;
	input->len = ft_strlen(str);
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
	if (g_info->precision_len >= 0)
		str = ft_substr(input_str, 0, g_info->precision_len);
	else
		str = ft_strdup(input_str);
	if (!str)
		return (0);
	input->len = ft_strlen(str);
	input->str = str;
	return (1);
}
