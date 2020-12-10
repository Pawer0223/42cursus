#include "printf.h"
#include "libft.h"

void			remove_zero(t_input	*input)
{
	int i;
	int j;
	char* str;

	str = input->str;
	i = 2;
	while (str[i] && str[i] == '0')
		i++;
	if (i > 2)
	{
		j = 2;
		while (str[i])
			str[j++] = str[i++];
		str[j] = 0;
		input->len = ft_strlen(str);
	}
}

void			fill_str_p(t_input* input, unsigned long long n, int idx)
{
	int		nmg;
	int		start;

	start = 0;
	if (input->sign)
		input->str[start++] = input->sign;
	input->str[start++] = '0';
	input->str[start++] = 'x';
	while (idx >= start)
	{
		nmg = n % 16;
		if (nmg >= 10)
			nmg = 'a' + (nmg % 10);
		else
			nmg = '0' + nmg;
		input->str[idx--] = nmg;
		n /= 16;
	}
}

int				setlen_p(t_input* input, unsigned long long n)
{
	int					len;

	len = 2;
	while (n != 0)
	{
		n /= 16;
		len++;
	}

	if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
	if (input->sign)
		len++;
	input->len = len;
	return (len);
}

int				set_p_zero(t_input *input)
{
	char	*str;
	if (!(str = (char*)malloc(sizeof(char) * 6)))
		return (0);
	ft_strlcpy(str, "(nil)", 6);
	input->len = 5;
	input->str = str;
	return (1);
}

int				set_p_input(unsigned long long n)
{
	t_input	*input;
	char	*str;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	if (n == 0)
		return set_p_zero(input);
	size = setlen_p(input, n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	input->str = str;
	str[size--] = 0;
	fill_str_p(input, n, size);
	remove_zero(input);
	return (1);
}