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

int			malloc_input_num(long long n)
{
	int		len;
	char	isMinus;

	len = (n <= 0 || g_info->sign_exist == 'Y') ? 1 : 0;
	isMinus = n < 0 ? 'Y' : 'N';
	if (n < 0)
		g_info->sign_exist = 'Y';
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (!(g_info->input = (char*)malloc(sizeof(char) * (size_t)(len + 1))))
		return (0);
	g_info->input[len] = 0;
	if (isMinus == 'Y')
		g_info->input[0] = '-';
	else if (g_info->sign_exist == 'Y')
		g_info->input[0] = g_info->flag;
	return (len);
}

void			set_input_num(long long n, int idx)
{
	long long nmg;
	if (n != 0)
	{
		set_input_num((n / 10), (idx - 1));
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		g_info->input[idx] = '0' + nmg;
	}
}

void		write_di(const char *format)
{
	long long	n;
	int			len;

	n = 0;
	if (g_info->length)
	{
		if (ft_strncmp(g_info->length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), long int);
		else if (ft_strncmp(g_info->length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), long long int);
		else if (ft_strncmp(g_info->length, "h", 3) == 0)
			n = va_arg(*(g_info->ap), short int);
		else if (ft_strncmp(g_info->length, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), signed char);
	}
	else
		n = va_arg(*(g_info->ap), int);
	if (!(len = malloc_input_num(n)))
		return (0);
	set_input_num(n, len - 1);
}

int		write_format(const char *format)
{
	char c;
	c = g_info->specifier;

	if (c == 'd' || c == 'i')
		write_di(format);
	//else if (c == 'u' || c == 'x' || c == 'x')
	//	write_di(format);
	//else if (c == 'c')
	//	write_di(format);
	//else if (c == 's')
	//	write_di(format);
	//else if (c == 'p')
	//	write_di(format);
	//else if (c == 'n')
	//	write_di(format);
	//else if (c == 'f' || c == 'g' || c == 'e')
	//	write_di(format);
}
/* input format_check */
int		check_format(const char *format)
{
	if (format[++g_i] && check_flag(format[g_i]))
		g_i++;
	if (!format[g_i] || !check_size(format, 1))
		return (0);
	if (format[g_i] == '.')
	{
		g_i++;
		if (check_size(format, 2))
			return (0);
	}
	if (!format[g_i] || !check_len(format))
		return (0);
	if (!format[g_i] || !check_spec(format))
		return (0);
	if (!write_format(format))
		return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list 		ap;

	printf("### input format is : [%s] ### \n", format);
	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			if (!check_format(format))
			{
				free_g();
				return (0);
			}
			struct_print();
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
