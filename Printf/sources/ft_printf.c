#include "printf.h"
#include "libft.h"

int			is_percent(char c)
{
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		g_i++;
		return (1);
	}
	return (0);
}

int			format_write_start(const char *format)
{
	if (!is_percent(format[++g_i]))
	{
		if (!check_format(format) || !ft_set_input_filter(g_info->specifier))
		{
			free_g();
			return (0);
		}
		if (g_info->specifier != 'n')
			ft_format_write(g_info->flag);
		// all_print();
		clear_g();
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list 		ap;

	// printf("### input format is : [%s] ### \n", format);
	va_start(ap, format);
	init_g(&ap);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			if (!format_write_start(format))
				return (0);
		}
		else
		{
			ft_putchar_fd(format[g_i], 1);
			g_i++;
			g_w_cnt++;
		}
	}
	free_g();
}
