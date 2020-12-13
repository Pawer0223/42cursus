#include "printf.h"

void			fill_is_zero(t_input *input, int idx)
{
	if (g_info->precision_len == 0)
	{
		input->str[idx] = 0;
		input->len = 0;
	}
	else
		input->str[idx] = '0';
}

int		get_len_ll(long long n)
{
	int len;
	int nmg;

	len = n <= 0 ? 1 : 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_lltoa(long long n)
{
	char		*str;
	long long	num;
	int			len;
	int			start;



	num = n;
	len = get_len(num);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	start = 0;
	if (num < 0)
	{
		num *= -1;
		str[start] = '-';
		start++;
	}
	while (len >= start)
	{
		str[len] = '0' + (num % 10);
		num /= 10;
		len--;
	}
	return (str);
}