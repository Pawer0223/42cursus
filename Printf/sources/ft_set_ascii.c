#include "printf.h"

int				set_ascii_input(int n)
{
	t_input	*input;
	char	*str;

	if (!(input = (t_input*)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
	input->len = 1;
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	input->str = str;
	str[1] = 0;
	str[0] = (char)n;
	return (1);
}