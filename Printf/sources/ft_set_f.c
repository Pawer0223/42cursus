#include "printf.h"
#include "libft.h"

void			set_f_sign(t_input *input, double n)
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

int         fill_str_f(char *str, double n, int len, int idx)
{
    int  is_left;

    is_left = idx == 0 ? 1 : 0;
    while (idx < len)
    {
        n *= 10;
        str[idx++] = (int)n + '0';
        n -= (int)n;
    }
    if (is_left)
        str[idx++] = '.';
    str[idx] = 0;
    return (idx);
}

int			check_signif(double n)
{
    int limit;
    int i;
    int strt;

    limit = 16;
    n = get_digit_d(n, limit);
    i = 0;
    strt = g_info->precision_len + 1;
    while (i < limit)
    {
        n *= 10;
        n = (int)n;
        if (i > strt && (int)n != 0)
            return (0);
        n -= (int)n;
        i++;
    }
    return (1);
}

void        round_up(char *str, int idx, int len)
{
    int prev;

    if (idx < 0)
    {
        str[len + 1] = 0;
        while (len > 0)
        {
            str[len] = str[len - 1];
            len--;
        }
        str[0] = (prev / 10) + '0';
        return;
    }
    prev = str[idx] - '0' + 1;
    if (g_info->precision_len == 0)
    {
        str[0] = (prev / 10) + '0';
        str[1] = (prev % 10) + '0';
        str[2] = 0;
        return;
    }
    str[idx--] = (prev % 10) + '0';
    if ((prev / 10 )> 0)
        round_up(str, idx, len);
}

void        ft_round(char *str, int idx, int pre, double n)
{
    int last;
    int prev;

    last = str[idx--] - '0';
    prev = pre == 0 ? str[--idx] - '0' : str[idx] - '0';
    str[idx + 1] = 0;
    if (last >= 5)
    {
        if ((prev % 2 == 0) && !check_signif(n))
            str[++idx] = 0;
        else
        {
            str[idx + 1] = 0;
            if ((prev + 1) > 9)
                round_up(str, idx, ft_strlen(str));
            else
                str[idx++] = prev + 1 + '0';
            return;
        }
    }
}


int         make_floating(t_input *input, double n)
{
    char    *str;
    int     len;
    int     i;
    double  left;
    double  right;

    int     left_len;
    int     right_len;

    left = get_number(n, 0);
    right = n - left;
    left_len = get_left_size(n);
    left_len = left_len == 0 ? 1 : left_len;
    right_len = g_info->precision_len + 1;
    left *= ft_pow(10, (left_len * -1));
    len = left_len + right_len + 10;
    if (!(str = (char*)malloc(sizeof(char) * len)))
        return (0);
    ft_bzero(str, len);
    input->str = str;
    i = 0;
    i = fill_str_f(str, left, left_len, i);
    right = get_digit_d(right, right_len);
    i = fill_str_f(str, right, right_len + i, i);
    ft_round(str, i - 1, right_len - 1, n);
    input->len = ft_strlen(str);
    return (1);
}

int				set_f_input(double n)
{
	t_input	*input;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
    set_f_sign(input, n);
    if (!make_floating(input, n))
        return (0);

	return (1);
}