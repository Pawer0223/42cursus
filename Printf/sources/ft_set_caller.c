#include "../headers/printf.h"

int				ft_set_di(char	*length)
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

int				ft_set_ux(char	*length, char spec)
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

int				ft_set_c(char	*length)
{
	int c;

	c = va_arg(*(g_info->ap), int);
	if (length && ft_strncmp(length, "l", 3) == 0)
	{
		printf(" 어떻게 wide char를 다룰 수 있을까..\n");
		// return set_uni_input(c);
		return (0);
	}
	else
		return set_ascii_input(c);
}

int				ft_set_s(char	*length)
{
	char	*str;
	wchar_t	*wstr;

	if (length && ft_strncmp(length, "l", 3) == 0)
	{
		printf(" 어떻게 wide char 문자열을 다룰 수 있을까..\n");
		wstr = va_arg(*(g_info->ap), wchar_t *);
		// return set_uni_input(wstr);
		return (0);
	}
	else
	{
		str = va_arg(*(g_info->ap), char *);
		return set_str_input(str);
	}
}

int				ft_set_p(h)
{
	unsigned long long n;

	n = va_arg(*(g_info->ap), void *);
	return set_p_input(n);
}