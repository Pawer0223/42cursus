#include "printf.h"
#include "libft.h"

void			set_f_sign(t_input *input, double n)
{
    int     sign;

    sign = n < 0 ? 1 : 0;
	if (sign == 1)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;

    if (g_info->precision_len == -1)
        g_info->precision_len = 6;
    printf("sign : [%d]\n", sign);
}

double		temp(double d)
{
    printf("## before : [%f]\n", d);
    d = ft_round(d, g_info->precision_len);
    printf("## After : [%f]\n", d);

    return (0);
}

int				set_f_input(double n)
{
	t_input	*input;
    char	*str;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;

    set_f_sign(input, n);

    temp(n);

    // 1. �����ο�, �Ǽ��θ� �����Ѵ�.

    // 2. precision_len ������ round �����Ѵ�.
        // �� precison_len�� 0�̸�, �����ΰ� ������ ��ġ�Ƿ� �ø� �Ǵ� ��쿡 ������ + 1 �Ѵ�.
        // �� 0�ʰ��� ��, �����α��� �ø��� �Ǹ�, ������ + 1 �ؾ� �ȴ�.
        // �� 0�ʰ��� ��, �����α��� �ø����� ���� ��, �Ǽ��� ���길 �����ϸ� �ȴ�.

    // 3. ������ ��� str �����

    // 4. �Ǽ��θ� precsion_len��ŭ �Ǽ��� �����.

    // 5. 3 + 4 ��ġ��

    // 6. input ä���ֱ�.

	return (0);
}