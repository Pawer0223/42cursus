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