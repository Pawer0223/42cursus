///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_printf.c                                        :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2020/11/08 17:35:48 by taekang           #+#    #+#             */
///*   Updated: 2020/11/23 19:07:11 by taekang          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "printf.h"
//#include "libft.h"
//
//void			fill_str_x(char* str, unsigned long long n, int idx, char sign)
//{
//	unsigned long long nmg;
//
//	if (n != 0)
//	{
//		fill_str_u(str, (n / 10), (idx - 1), sign);
//		nmg = n % 10;
//		if (nmg < 0)
//			nmg *= -1;
//		str[idx] = ('0' + nmg);
//		// printf("str[%d]:%c\n", idx ,str[idx]);
//	}
//	else
//	{
//		if (sign && idx >= 0)
//			str[idx--] = sign;
//		while (idx >= 0)
//			str[idx--] = '0';
//	}
//}
//
//void			convert_hexa(t_input* input, unsigned long long n)
//{
//	int len;
//
//	len = 0;
//	while (n != 0)
//	{
//		n /= 16;
//	}
//}
//
//int				setlen_u(t_input* input, unsigned long long n)
//{
//	int	len;
//
//	len = 0;
//	while (n != 0)
//	{
//		n /= 16;
//		len++;
//	}
//	if ((g_info->precision_len) > len)
//		len = g_info->precision_len;
//	input->len = len;
//	return (len);
//}
//
//int				set_x_input(unsigned long long n)
//{
//	t_input* input;
//	char* str;
//	int		size;
//
//	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
//		return (0);
//	convert_hexa(input, n);
//	size = setlen_x(input, n);
//	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
//		return (0);
//	str[size] = 0;
//	fill_str_x(str, n, size - 1, input->sign);
//	input->str = str;
//	g_info->input = input;
//	return (1);
//}