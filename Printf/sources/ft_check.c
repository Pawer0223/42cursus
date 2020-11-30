#include "printf.h"
#include "libft.h"

/* flag exist = return 0 else return 1 */
void			check_flag(const char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		g_info->flag = c;
		g_i++;
	}
}
/* type1 = set width, type2 = set precision_len */
int			check_size(const char *format, int type)
{
	int		start;
	char	*num;
	size_t	len;

	start = g_i;
	while (format[g_i] && ft_isdigit(format[g_i]))
		g_i++;
	if (start != g_i)
	{
		len = (size_t)(g_i - start);
		if (!(num = ft_substr(format, (unsigned int)start, len)))
			return (0);
		else
		{
			if (type == 1)
				g_info->width = ft_atoi(num);
			else
				g_info->precision_len = ft_atoi(num);
		}
		free(num);
	}
	return (1);
}
/* malloc error is return 0 */
int			check_len(const char *format)
{
	char*	len;
	int		seq;

	seq = 0;
	if (format[g_i] == 'l' || format[g_i] == 'h')
	{
		if (!(len = (char*)malloc(sizeof(char) * 3)))
			return (0);
		len[seq++] = format[g_i++];
		if (format[g_i] == len[0])
			len[seq++] = format[g_i++];
		len[seq] = 0;
		g_info->length = len;
	}
	return (1);
}
/* specifier exist return 1 else return 0 */
int			check_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'n' || c == 'f'
		|| c == 'g' || c == 'e')
	{
		g_info->specifier = c;
		g_i++;
		return (1);
	}
	return (0);
}

/* input format_check */
int		check_format(const char* format)
{
	check_flag(format[g_i]);
	if (!format[g_i] || !check_size(format, 1))
		return (0);
	if (format[g_i] == '.')
	{
		g_info->precision_len = 0;
		if (!format[++g_i] || !check_size(format, 2))
			return (0);
	}
	if (!format[g_i] || !check_len(format))
		return (0);
	if (!format[g_i] || !check_spec(format[g_i]))
		return (0);
	return (1);
}