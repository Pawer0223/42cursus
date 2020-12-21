#include "printf.h"
#include "libft.h"

void            set_f_sign(t_input *input, double n)
{
    int     sign;

    sign = n < 0 ? 1 : 0;
	if (sign == 1)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;

    if (g_info->precision_len == -1)
        g_info->precision_len = 6;
}

int             fill_str_f(t_input *input, double n, int len, int idx)
{
    int     is_left;
    int     num;
    char    *str;

    is_left = (idx == 0) ? 1 : 0;
    str = input->str;
    if (is_left && input->sign)
    {
        str[idx++] = input->sign;
        len++;
    }
    while (idx < len)
    {
        n *= 10;
        num = (int)n < 0 ? (int)n * -1 : (int)n;
        str[idx++] = num + '0';
        n -= (int)n;
    }
    if (is_left)
        str[idx++] = '.';
    str[idx] = 0;
    return (idx);
}

int             make_floating(t_input *input, double n , double left, double right)
{
    char    *str;
    int     i;
    int     left_len;
    int     right_len;

    left_len = get_left_size(n);
    left_len = left_len == 0 ? 1 : left_len;
    right_len = g_info->precision_len + 1;
    left *= ft_pow(10, (left_len * -1));
    if (!(str = (char*)malloc(sizeof(char) * left_len + right_len + 10)))
        return (0);
    ft_bzero(str, left_len + right_len + 10);
    input->str = str;
    i = 0;
    i = fill_str_f(input, left, left_len, i);
    i = fill_str_f(input, right, right_len + i, i);
    ft_round(str, i - 1, g_info->precision_len, right);
    input->len = ft_strlen(str);
    return (1);
}

int             set_f_input(double n)
{
	t_input	*input;
	int		size;
    double  left;
    double  right;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
    set_f_sign(input, n);
    left = get_number(n, 0);
    right = n - left;
    if (!make_floating(input, n, left, right))
        return (0);
	return (1);
}