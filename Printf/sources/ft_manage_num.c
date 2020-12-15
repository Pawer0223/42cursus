#include "printf.h"

int			get_left_size(double d)
{
	int     left_size;

	left_size = 0;
	while (d > 1)
	{
		d /= 10;
		left_size++;
	}
	return (left_size);
}

double		get_number(double d, int need_last)
{
	double  left;
	int     expo;
	int		last;

	expo = get_left_size(d);
	left = 0;
	last = 0;
	while (expo > 0)
	{
		d *= 10;
		left += (int)d * ft_pow(10, --expo);
		last = (int)d;
		d -= (int)d;
	}
	if (need_last)
		return (last);
	return (left);
}