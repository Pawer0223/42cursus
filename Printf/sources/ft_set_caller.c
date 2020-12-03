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

int				ft_set_c(char* length)
{
	wint_t lc;
	char c;
	
	// 아이거 VA_ARG 형승격으로 다 int로 해야하는 갑다..
	if (length && ft_strncmp(length, "l", 3) == 0)
	{
		lc = va_arg(*(g_info->ap), wint_t);
		// return set_di_input(n);
	}
	else
	{
		c = va_arg(*(g_info->ap), int);
	}
	return (0);
}