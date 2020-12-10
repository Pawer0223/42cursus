//#include "printf.h"
//#include "libft.h"
//
//void			fill_str_u(t_input* input, long long n, int idx)
//{
//	if (n == 0)
//		fill_is_zero(input, idx--);
//	while (idx >= 0 && n != 0)
//	{
//		input->str[idx--] = '0' + (n % 10);
//		n /= 10;
//	}
//	while (idx >= 0)
//		input->str[idx--] = '0';
//}
//
//int				setlen_f(t_input *input, double n)
//{
//	int	len;
//
//	len = (n == 0) ? 1 : 0;
//	while (n != 0)
//	{
//		n /= 10;
//		len++;
//	}
//	if ((g_info->precision_len) > len)
//		len = g_info->precision_len;
//	input->len = len;
//	return (len);
//}
//
///*
//	bit 찾을 수 있음.
//	가수부, 지수부
//*/
//int				set_f_input(double n)
//{
//	t_input	*input;
//	char	*str;
//	int		size;
//
//	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
//		return (0);
//	g_info->input = input;
//	size = setlen_f(input, n);
//	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
//		return (0);
//	input->str = str;
//	str[size--] = 0;
//	fill_str_u(input, n, size);
//	return (1);
//}