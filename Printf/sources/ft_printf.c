/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:35:48 by taekang           #+#    #+#             */
/*   Updated: 2020/11/23 19:07:11 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	check_flag(const char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		g_info->flag = c;
	else if(c == '%')
	{
		char percent= '%';
		write(1, &percent, 1);
	}
	printf("flag:[%c]\n",g_info->flag);
}

void	check_width(const char *format)
{
	int	start;
	char			*num;

	start = g_i;
	while (format[g_i] && ft_isdigit(format[g_i]))
		g_i++;
	if (start != g_i)
	{
		num = ft_substr(format, (unsigned int)start, (size_t)(g_i - start));
		printf("nums is :[%s]\n",num);
		g_info->width = ft_atoi(num);
		free(num);
	}
	printf("g_info->width : %d\n", g_info->width);
}

void	format_write(const char *format)
{
	printf("\nformat_write\n");

	if (format[++g_i])
		check_flag(format[g_i]);
	if (format[++g_i])
		check_width(format);
	//if (format[g_i] == '.')
		//check_pre_len(format);
}
void	start(const char *format, ...)
{
	va_list 		ap;

	printf("input format is : [%s]\n", format);
	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			format_write(format);
			clear_g();
		}
		else
		{
			write(1, format + g_i, 1);
			g_i++;
		}
	}
	free_g();
}
