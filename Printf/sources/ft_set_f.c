#include "printf.h"
#include "libft.h"

void			fill_str_left(t_input* input, long long n, int idx)
{
	int nmg;

	if (n == 0)
		input->str[idx--] = '0';
	while (idx >= 0 && n != 0)
	{
		nmg = n % 10;
		if (nmg < 0)
			nmg *= -1;
		input->str[idx--] = '0' + nmg;
		n /= 10;
	}
	if (input->sign && idx >= 0)
		input->str[idx--] = input->sign;
	while (idx >= 0)
		input->str[idx--] = '0';
}

void			fill_str_f(t_input *input, double n, int idx)
{
	int			num;
	int			i;
	long long	ll;
	double		d;
	int			len_r;
	int			pre_len;

	ll = n;
	d = n - ll;
	pre_len = g_info->precision_len;

	if (pre_len != -1)
		len_r = pre_len;
	else
		len_r = 6;
	i = idx - len_r;
	if (len_r != 0)
		input->str[i--] = '.';
	fill_str_left(input, ll, i);
	i += 2;
	while (i < input->len)
	{
		num = d * 10;
		d = (d * 10) - num;
		if (num < 0)
			num *= -1;
		input->str[i++] = num + '0';
	}
}

void			set_f_sign(t_input *input, double n)
{
	if (n < 0)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
}

int				setlen_f(t_input *input, double n)
{
	int			len;
	int			pre_len;
	long long	ll;

	ll = n;
	pre_len = g_info->precision_len;
	len = (ll == 0) ? 1 : 0;
	while (ll != 0)
	{
		ll /= 10;
		len++;
	}
	if (pre_len != -1)
		len += pre_len;
	else
		len += 7;
	if (pre_len != 0)
		len++;
	if (input->sign)
		len++;
	input->len = len;
	return (len);
}

int				set_f_input(double n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	set_f_sign(input, n);
	size = setlen_f(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	fill_str_f(input, n, size);
	return (1);
}