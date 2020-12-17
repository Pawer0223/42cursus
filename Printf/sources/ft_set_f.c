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

void         fill_str_f(double n, char *temp, int len, char l_or_r)
{
    int i;

    i = 0;
    while (i < len)
    {
        n *= 10;
        temp[i++] = (int)n + '0';
        n -= (int)n;
    }
    if (l_or_r == 'l' && g_info->precision_len > 0)
        temp[i++] = '.';
    temp[i] = 0;
    return (1);
}


int         make_floating(t_input *input, double n)
{
    char    *l;
    char    *r;
    int     len;
    double  left;
    double  right;

    left = get_number(n, 0);
    right = n - left;

    len = get_left_size(n);
    len = len == 0 ? 1 : len;
    left *= ft_pow(10, (len * -1));
    if (!(l = (char*)malloc(sizeof(char) * len + 2)))
        return (0);
    fill_str_f(left, l, len, 'l');
    len = g_info->precision_len;
    right = get_digit_d(right, len);
    if (!(r = (char*)malloc(sizeof(char) * len + 1)))
    {
        free(l);
        return (0);
    }
    fill_str_f(right, r, len, 'r');
    input->str = ft_strjoin(l, r);
    input->len = ft_strlen(input->str);
    free(l);
    free(r);
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
    printf("## before : [%.21f]\n", n);
    n = ft_round(n, g_info->precision_len);
    printf("## After: [%.21f]\n", n);
    if (!make_floating(input, n))
        return (0);

	return (1);
}