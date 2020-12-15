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

int				get_bit(char *ptr, int byte, int bit)
{
	return (*(ptr + byte) >> bit) & 0x01;
}

double			read_bit(char *str, int exponent)
{
	int		idx;
	int		increase;
	double	result;
	
	increase = (exponent < 0) ? -1 : 1;
	idx = 0;
	result = 0;
	while (str[idx])
	{
		if (str[idx] == '1')
			result += ft_pow(2, exponent);
		idx++;
		exponent += increase;
	}
	return (result);
}