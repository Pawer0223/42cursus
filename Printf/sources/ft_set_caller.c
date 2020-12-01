#include "printf.h"

int				ft_set_di(char* length)
{
	long long	n;

	n = 0;
	if (length)
	{
		if (ft_strncmp(length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), long int);
		else if (ft_strncmp(length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), long long int);
	}
	else
		n = va_arg(*(g_info->ap), int);
	return set_di_input(n);
}

int				ft_set_ux(char* length, char spec)
{
	unsigned long long	n;

	n = 0;

	if (length)
	{
		if (ft_strncmp(length, "l", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long int);
		else if (ft_strncmp(length, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long long int);
	}
	else
		n = va_arg(*(g_info->ap), unsigned int);
	if (spec == 'u')
		return set_u_input(n);
	else
		return set_x_input(n);
}