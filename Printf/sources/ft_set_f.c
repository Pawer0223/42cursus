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

    // 1. 정수부와, 실수부를 구분한다.

    // 2. precision_len 에따라 round 수행한다.
        // ㄴ precison_len이 0이면, 정수부가 영향을 끼치므로 올림 되는 경우에 정수부 + 1 한다.
        // ㄴ 0초과일 때, 정수부까지 올림이 되면, 정수부 + 1 해야 된다.
        // ㄴ 0초과일 때, 정수부까지 올림되지 않을 땐, 실수부 연산만 진행하면 된다.

    // 3. 정수부 모두 str 만들기

    // 4. 실수부를 precsion_len만큼 실수부 만들기.

    // 5. 3 + 4 합치기

    // 6. input 채워주기.

	return (0);
}