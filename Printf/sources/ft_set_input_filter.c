#include "printf.h"

int		ft_set_input_filter(char spec)
{
	if (spec == 'd' || spec == 'i')
		ft_set_di(g_info->length);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		ft_set_ux(g_info->length, spec);
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