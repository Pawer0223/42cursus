#include "printf.h"
#include "libft.h"

void			set_f_sign(t_input *input, char *ptr, int len)
{
    int     sign;

    sign = ((*(ptr + len) >> 7) & 0x01) == 0 ? 1 : -1;
	if (sign == 1)
		input->sign = '-';
	else if (g_info->flag == ' ' || g_info->flag == '+')
		input->sign = g_info->flag;
	else
		input->sign = 0;
    printf("sign : [%d]\n", sign);
}
int             read_exponent(char *ptr, int byte_strt)
{
    int expo_cnt;
    int n;
    int i;
    int j;

    n = 0;
    expo_cnt = 10;
    i = byte_strt;
    while (i >= byte_strt - 1)
    {
        j = (i == byte_strt) ? 6 : 7;
        while (expo_cnt >= 0 && j >= 0)
        {
            if (get_bit(ptr, i, j) == 1)
                n += ft_pow(2, expo_cnt);
            expo_cnt--;
            j--;
        }
        i--;
    }
    n -= 1023;
    return n;
}
double      read_mantissa(char* ptr, int byte_idx, int bit_idx, int byte_len)
{
    int     idx;
    char    *mantissa;

    idx = 0;
    if (!(mantissa = (char*)malloc(sizeof(char) * 52)))
        return (0);
    while (byte_idx >= 0)
    {
        while (bit_idx >= 0)
        {
            // printf("byte :[%d], bit [%d]\n", byte_idx, bit_idx);
            mantissa[idx++] = get_bit(ptr, byte_idx, bit_idx) + '0';
            bit_idx--;
        }
        bit_idx = 7;
        byte_idx--;
    }
    mantissa[idx] = 0;
    printf("mantisa is : [%s]\n", mantissa);

    double result = 0;
    idx = 0;
    int cnt = -1;
    while (mantissa[idx])
    {
        if (mantissa[idx] == '1')
            result += ft_pow(2, cnt);
        idx++;
        cnt--;
    }
    // free 꼭해줘야함 !!!!!!!!!!!!!! 근데 합치고 나서 !!!!!
    free(mantissa);
    return (result);
}

double      read_mantissa_backup(char *ptr, int byte_strt, int bit_strt, int byte_len)
{
    int     j;
    int     mant_expo;
    double  mantissa;

    mantissa = 0;
    mant_expo = -1;
    j = 3;
    while (byte_len >= 0)
    {
        while (j >= 0)
        {
            if (byte_len <= byte_strt && j <= bit_strt)
            {
                if (get_bit(ptr, byte_len, j) == 1)
                    mantissa += ft_pow(2, mant_expo);
            }
            mant_expo--;
            j--;
        }
        byte_len--;
        j = 7;
    }
    return (mantissa);
}
/* sign 1, exponent 11, mantissa 52 */
void        read_floating(t_input *input, double d, char *ptr)
{
    int             len;
    int             byte_strt;
    int             bit_strt;
    int             n;
    double          mantissa;

    len = sizeof(double) - 1;
    set_f_sign(input, ptr, len);
    /* base 일반적으로 다 읽는 경우의 인자 값 */
    n = read_exponent(ptr, len);

    byte_strt = 6 - (n + 4) / 8;
    bit_strt = 7 - ((n + 4) % 8);
    if (n >= 1 && n <= 51)
        mantissa = read_mantissa(ptr, byte_strt, bit_strt, len - 1);
    else if (n >= 52)
    {
        printf("n >= 52\n");
    }
    else if (n < 0)
    {
        printf("n < 0\n");
    }
    printf("mantissa : [%f], n : [%d] \n", mantissa, n);
    double result = ft_pow(2, n) * mantissa;
    printf("result is : %f\n", result);
    printf("result %%.20f is : %.20f\n", result);
    printf("origin %%.20f is : %.20f\n", d);
}

int				set_f_input(double n)
{
	t_input	*input;
    char	*str;
    char    *ptr;
	int		size;

	if (!(input = (t_input *)(malloc(sizeof(t_input)))))
		return (0);
	g_info->input = input;
    ptr = (char*)&n;
    read_floating(input, n, ptr);


    // 저장방식해석 해서 자릿수 판단한기.

    // 부호비트 확인

    // 지수비트 확인
    /*
        1. 지수비트의 값이 0~51인 경우, 정수 실수 구분 가능하니깐 bit해석하면 끝.
        2. 지수비트의 값이 52이상인 경우, 해당값은 정수다.
            2-1) 이때 소수점은 근사값때문에 뭣이나오든 0으로만 출력한다.
            2-2) 어떻게 정수값만 출력을 할 수 있는가?
                ㄴ 1001.000000 이라면?
                ㄴ /10을하면, 100.1 됨. 소수점 .1을 기록하고 버려야 함.
                ㄴ 그렇다면, 100.1 - 100 의 결과는 0.1xxxx 될꺼고.. 
                ㄴ 이거를 다시 10 곱하면, 1.xxxx 될꺼니깐.. 여기서 1을 추출
                ㄴ 이걸 반복..
        3. 지수비트의 값이 0미만인 경우, 해당 값은 0.xxxxx 이다.
            3-1) 실수부만 출력한다.
                ㄴ HOW ?
                ㄴ 이건.. 그냥 정수부는 [0.] 붙이고, precision_len이 없으면 6자리만, 있으면 precision_len 만큼 반복해서 추출.
    */

  

    
	//size = setlen_f(input, n);
	//if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
	//	return (0);
	//input->str = str;
	//str[size--] = 0;
	//fill_str_f(input, n, size);
	return (0);
}