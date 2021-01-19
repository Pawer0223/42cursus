
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:06:42 by taekang           #+#    #+#             */
/*   Updated: 2021/01/19 01:03:56 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// remove
#include <stdio.h>

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int		get_num_value(const char *format, int *i)
{
	int len;

	len = 0;
	while (format[*i] && is_digit(format[*i]))
	{
		len = (len * 10) + (format[*i] - '0'); 
		*i += 1;
	}
	return (len);
}

void	write_str(char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*result;
	int		i;

	if (!str)
		return (0);
	if (start >= ft_strlen(str))
		return ft_strdup("");
	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (str[start] && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}

char	*str_null(int p_l)
{
	char	*nul_str;
	char	*substr;

	nul_str = ft_strdup("(null)");
	if (!nul_str)
		return (0);
	if (p_l >= 0)
	{
		substr = ft_substr(nul_str, 0, p_l);
		free(nul_str);
		return (substr);
	}
	return (nul_str);
}

char	*get_s(int p_l, char *arg)
{
	char	*str;

	if (!arg)
		return (str_null(p_l));
	if (p_l < 0)
		str = ft_strdup(arg);
	else
		str = ft_substr(arg, 0, p_l);
	return (str);
}

char	*get_d(int p_l, int n)
{
	char	*str;
	long	l;
	int		is_minus;
	int		len;

	l = (long)n;
	len = (n <= 0) ? 1 : 0;
	is_minus = (n < 0) ? 1 : 0;
	l = (is_minus) ? (l * -1) : l;
	while (l != 0)
	{
		l /= 10;
		len++;
	}
	p_l = (is_minus) ? p_l + 1 : p_l;
	if (p_l > len)
		len = p_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = 0;
	if (n == 0 && p_l == 0)
		str[len--] = 0;
	l = (long)n;
	l = (is_minus) ? (l * -1) : l;
	while (l != 0)
	{
		str[len--] = (l % 10) + '0';
		l /= 10;
	}
	while (len >= 0)
		str[len--] = '0';
	if (is_minus)
		str[0] = '-';
	return (str);
}

char	*get_x(int p_l, unsigned int x)
{
	char			*str;
	unsigned int	temp;
	int				len;
	int				nmg;

	temp = x;
	len = (x == 0) ? 1 : 0;
	while (temp != 0)
	{
		temp /= 16;
		len++;
	}
	if (p_l > len)
		len = p_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = 0;
	if (x == 0 && p_l == 0)
		str[len--] = 0;
	while (x != 0)
	{
		nmg = x % 16;
		if (nmg >= 10)
			nmg = ('a' + (nmg % 10));
		else
			nmg = nmg + '0';
		str[len--] = nmg;
		x /= 16;
	}
	while (len >= 0)
		str[len--] = '0';
	return (str);
}

char	*check_format(char spec, va_list ap, int pre_len)
{
	char	*str;

	str = 0;

	if (spec == 's')
		str = get_s(pre_len, va_arg(ap, char *));
	else if (spec == 'd')
		str = get_d(pre_len, va_arg(ap, int));
	else if (spec == 'x')
		str = get_x(pre_len, va_arg(ap, unsigned int));
	else
		write_str("not manage specifier");

	if (!str)
		return (0);
	// printf("specifier => [%c]\n", specifier);

	return (str);
}

void	format_write(char *result, int w)
{
	char	padding;
	int		r_len;
	int		p_len;
	
	padding = ' ';
	r_len = ft_strlen(result);
	p_len = w - r_len;

	while (p_len > 0)
	{
		write(1, &padding, 1);
		p_len--;
	}
	write_str(result);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		w_cnt;
	int		width;
	int		pre_len;
	int		result_len;
	char	*result;

	va_start(ap, format);
	i = 0;
	w_cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0;
			pre_len = -1;
			width = get_num_value(format, &i);
			if (format[i] == '.')
			{
				i++;
				pre_len = get_num_value(format, &i);
			}
			// printf("width : %d, pre_len : %d\n", width, pre_len);
			result = check_format(format[i++], ap, pre_len);
			// printf("result : [%s]\n", result);
			if (!result)
				return (0);
			// format write
			format_write(result, width);
			result_len = ft_strlen(result);
			if (width > result_len)
				w_cnt += width;
			else
				w_cnt += result_len;
			free(result);
		}
		else
		{
			write(1, format + i, 1);
			w_cnt++;
			i++;
		}
	}
	va_end(ap);
	return (w_cnt);
}

// int		main(void)
// {
// 	int a = ft_printf("[%12.10d]\n", 1000);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%12.10d]\n", 1000);
// 	printf("cnt => [%d]\n", a);
// 	a = ft_printf("[%3.d]\n", 0);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%3.d]\n", 0);
// 	printf("cnt => [%d]\n", a);
// 	a = ft_printf("[%5.6d]\n", -12);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%5.6d]\n", -12);
// 	printf("cnt => [%d]\n", a);
// 	a = ft_printf("[%d]\n", (int)-2147483648);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%d]\n", (int)-2147483648);
// 	printf("cnt => [%d]\n", a);
// 
// 
// 	printf("######## x ##########\n");
// 	a = ft_printf("[%x]\n", 2147483647);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%x]\n", 2147483647);
// 	printf("cnt => [%d]\n", a);
// 
// 	a = ft_printf("[%20.8x]\n", 12345);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%20.8x]\n", 12345);
// 	printf("cnt => [%d]\n", a);
// 	
// 	a = ft_printf("[%5.x]\n", 0);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%5.x]\n", 0);
// 	printf("cnt => [%d]\n", a);
// 	
// 	printf("######## s ##########\n");
// 
// 	char *zero;
// 	zero = 0;
// 	a = ft_printf("[%s]\n", zero);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%s]\n", zero);
// 	printf("cnt => [%d]\n", a);
// 
// 	char *str = "taesan hi !";	
// 	a = ft_printf("[%20.6s]\n", str);
// 	printf("cnt => [%d]\n", a);
// 	a = printf("[%20.6s]\n", str);
// 	printf("cnt => [%d]\n", a);
// //	ft_printf("10 is [%d]\n", 10);
// //	ft_printf("-10 is [%d]\n", -10);
// //	ft_printf("0 is [%d]\n", 0);
// 	return (0);
// }
// 
 // int main(void)
 // {
 // 
 //    int a = ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
 //    int b =	printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
 // 	printf("my : [%d], computer : [%d]\n", a, b);
 // 
 // 	return (0);
 // }
