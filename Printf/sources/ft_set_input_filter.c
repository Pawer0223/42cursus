#include "../headers/printf.h"

int		ft_set_input_filter(char spec)
{
	if (spec == 'd' || spec == 'i')
		return ft_set_di(g_info->length);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		return ft_set_ux(g_info->length, spec);
	else if (spec == 'c')
		return ft_set_c(g_info->length);
	else if (spec == 's')
		return ft_set_s(g_info->length);
	else if (spec == 'p')
		return ft_set_p();
	else if (spec == 'n')
		ft_set_n(g_info->length);
	else if (spec == 'f' || spec == 'g' || spec == 'e')
		return ft_set_fge(g_info->length);
	return (1);
}