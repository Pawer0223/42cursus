//#include "printf.h"
//#include "libft.h"
//
//void			set_f_sign(t_input *input, double n)
//{
//	if (n < 0)
//		input->sign = '-';
//	else if (g_info->flag == ' ' || g_info->flag == '+')
//		input->sign = g_info->flag;
//	else
//		input->sign = 0;
//}
//
//int				setlen_f(t_input *input, double n)
//{
//	double d2 = n;
//
//	// 정수 범위
//
//	// 실수 범위
//
//	long long ll;
//	double d;
//
//	ll = n;
//	d = n - ll;
//	if (g_info->precision_len == 0)
//	{
//		if ((int)d * 10 >= 5 && (ll % 2 != 0))
//			ll += 1;
//	}
//
//
//}
//
//int				set_f_input(double n)
//{
//	t_input	*input;
//	char	*str;
//	int		size;
//
//	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
//		return (0);
//	g_info->input = input;
//	set_left_f(n);
//	set_f_sign(input, n);
//	size = setlen_f(input, n);
//	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
//		return (0);
//	input->str = str;
//	str[size--] = 0;
//	fill_str_f(input, n, size);
//	return (1);
//}