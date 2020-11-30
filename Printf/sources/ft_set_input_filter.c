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
		else if (ft_strncmp(length, "h", 3) == 0)
			n = va_arg(*(g_info->ap), short int);
		else if (ft_strncmp(length, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), signed char);
	}
	else
		n = va_arg(*(g_info->ap), int);
	if (!set_di_input(n))
		return (0);
	return (1);
}

int		ft_set_input_filter2(char spec)
{
	unsigned long long n;
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		n = get_n(spec, g_info->length);
	}

	return (1);
}


int		ft_set_input_filter(char spec)
{
	if (spec == 'd' || spec == 'i')
		ft_set_di(g_info->length);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		ft_set_ux(g_info->length);
	//else if (c == 'c')
	//	write_di(format);
	//else if (c == 's')
	//	write_di(format);
	//else if (c == 'p')
	//	write_di(format);
	//else if (c == 'n')
	//	write_di(format);
	//else if (c == 'f' || c == 'g' || c == 'e')
	//	write_di(format);
	return (1);
}

unsigned long long get_n(char spec, char *len)
{
	unsigned long long n;

	if (len && (spec == 'd' || spec == 'i'))
	{
		if (ft_strncmp(len, "l", 3) == 0)
			n = va_arg(*(g_info->ap), long int);
		else if (ft_strncmp(len, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), long long int);
		else if (ft_strncmp(len, "h", 3) == 0)
			n = va_arg(*(g_info->ap), short int);
		else if (ft_strncmp(len, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), signed char);
		else
			n = va_arg(*(g_info->ap), int);
	}
	else if (len && (spec == 'u' || spec == 'x' || spec == 'X'))
	{
		if (ft_strncmp(len, "l", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long int);
		else if (ft_strncmp(len, "ll", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned long long int);
		else if (ft_strncmp(len, "h", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned short int);
		else if (ft_strncmp(len, "hh", 3) == 0)
			n = va_arg(*(g_info->ap), unsigned char);
		else
			n = va_arg(*(g_info->ap), unsigned int);
	}
	return (n);
}