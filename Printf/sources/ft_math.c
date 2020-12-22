#include "../headers/printf.h"
#include "../headers/libft.h"

double		ft_pow(double base, double exponent)
{
	double	result;
	int		i;

	if ((int)exponent == 0)
		return (1);
	result = 1;
	i = 0;
	if (exponent < 0)
	{
		i = exponent;
		while (i++ < 0)
			result /= base;
	}
	else
	{
		while (i++ < exponent)
			result *= base;
	}
	return (result);
}

int			check_signif(double n)
{
    int limit;
    int i;
    int strt;

    limit = 16;
    i = 0;
    strt = g_info->precision_len + 1;
    while (i < limit)
    {
        n *= 10;
        if (i > strt && (int)n != 0)
            return (0);
        n -= (int)n;
        i++;
    }
    return (1);
}

void        round_up(char* str, int idx, int len)
{
    int prev;

    if (str[idx] == '.')
        idx--;
    prev = str[idx] - '0' + 1;
    if (g_info->precision_len == 0)
    {
        str[0] = (prev / 10) + '0';
        str[1] = (prev % 10) + '0';
        str[2] = 0;
        return;
    }
    str[idx--] = (prev % 10) + '0';
    if (idx == 0)
        str[idx] = (prev / 10) + '0';
    if ((prev / 10) > 0)
        round_up(str, idx, len);
}

void        ft_round(char* str, int idx, int pre, double n)
{
    int last;
    int prev;

    last = str[idx--] - '0';
    prev = pre == 0 ? str[--idx] - '0' : str[idx] - '0';
    str[idx + 1] = 0;
    if (last >= 5)
    {
        if (last == 5 && (prev % 2 == 0) && check_signif(n))
            str[++idx] = 0;
        else
        {
            if ((prev + 1) > 9)
                round_up(str, idx, ft_strlen(str));
            else
                str[idx++] = prev + 1 + '0';
            return;
        }
    }
}