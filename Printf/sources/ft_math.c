#include "printf.h"

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

int			check_signif(double r, int strt)
{
	int limit;
	int i;
	int n;

	limit = 16;
	i = 0;
	while (i < 16)
	{
		r *= 10;
		n = (int)r;
		if (i > strt&& n != 0)
			return (0);
		r -= (int)r;
		i++;
	}
	return (1);
}

double		pre_zero(double l, double r)
{
	int	signif;
	int	prev;

	signif = (int)(r * 10);
	prev = (int)get_number(l + r, 1) % 2;
	if (signif >= 5)
	{
		if (prev % 2 == 0 && check_signif(r, 0))
			return (l);
		l += 1;
	}
	return (l);
}

double		pre_not_zero(double l, double r, int pre)
{
	int		signif;
	int		prev;
	int		i;
	double	r2;

	i = 0;
	r2 = get_digit_d(r, pre + 1);
	while (i <= pre)
	{
		r2 *= 10;
		signif = (int)r2;
		if (i == pre - 1)
			prev = (int)r2;
		r2 -= (int)r2;
		i++;
	}
	if (signif >= 5)
	{
		if (prev % 2 == 0 && check_signif(r, pre + 1))
			return (l + r);
		r += ft_pow(10, (pre * -1));
	}
	return get_digit_d((l + r), pre);
}

double		ft_round(double d, int pre)
{
	double  left;
	double  right;

	left = get_number(d, 0);
	right = d - left;

	if (pre == 0)
		return (pre_zero(left, right));
	return (pre_not_zero(left, right, pre));
}