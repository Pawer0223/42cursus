//#include "printf.h"
//#include "libft.h"
//
//void			set_f_sign(t_input* input, char* ptr, int len)
//{
//    int     sign;
//
//    sign = ((*(ptr + len) >> 7) & 0x01) == 0 ? 1 : -1;
//    if (sign == 1)
//        input->sign = '-';
//    else if (g_info->flag == ' ' || g_info->flag == '+')
//        input->sign = g_info->flag;
//    else
//        input->sign = 0;
//    printf("sign : [%d]\n", sign);
//}
//int             read_exponent(char* ptr, int byte_strt)
//{
//    int expo_cnt;
//    int n;
//    int i;
//    int j;
//
//    n = 0;
//    expo_cnt = 10;
//    i = byte_strt;
//    while (i >= byte_strt - 1)
//    {
//        j = (i == byte_strt) ? 6 : 7;
//        while (expo_cnt >= 0 && j >= 0)
//        {
//            if (get_bit(ptr, i, j) == 1)
//                n += ft_pow(2, expo_cnt);
//            expo_cnt--;
//            j--;
//        }
//        i--;
//    }
//    n -= 1023;
//    return n;
//}
//
//char* make_mantissa(double mantissa, int pre)
//{
//    char* right;
//    int     i;
//    int     n;
//
//    if (!(right = (char*)malloc(sizeof(char) * pre + 1)))
//        return (0);
//    right[pre] = 0;
//    i = 0;
//
//    // round ����..
//
//    while (i < pre)
//    {
//        mantissa *= 10;
//        right[i++] = (int)mantissa;
//        mantissa -= (int)mantissa;
//    }
//    return (right);
//}
//
//char* read_mantissa(char* ptr, int byte_idx, int bit_idx, int byte_len)
//{
//    int     idx;
//    char* mantissa;
//    double  result;
//    int     exponent;
//
//    idx = 0;
//    if (!(mantissa = (char*)malloc(sizeof(char) * 52)))
//        return (0);
//    while (byte_idx >= 0)
//    {
//        while (bit_idx >= 0)
//        {
//            // printf("byte :[%d], bit [%d]\n", byte_idx, bit_idx);
//            mantissa[idx++] = get_bit(ptr, byte_idx, bit_idx) + '0';
//            bit_idx--;
//        }
//        bit_idx = 7;
//        byte_idx--;
//    }
//    mantissa[idx] = 0;
//    return make_mantissa(read_bit(mantissa, -1), 0);
//}
//
//char* make_floating(double d, char* ptr, int n, int len)
//{
//    int     byte_strt;
//    int     bit_strt;
//    char* mantissa;
//    char* num;
//
//    byte_strt = 6 - (n + 4) / 8;
//    bit_strt = 7 - ((n + 4) % 8);
//    if (n >= 1 && n <= 51)
//        mantissa = read_mantissa(ptr, byte_strt, bit_strt, len - 1);
//    else if (n >= 52)
//    {
//        printf("n >= 52\n");
//    }
//    else if (n < 0)
//    {
//        printf("n < 0\n");
//    }
//    return (0);
//
//}
///* sign 1, exponent 11, mantissa 52 */
//void        read_floating(t_input* input, double d, char* ptr)
//{
//    int len;
//    int n;
//
//    len = sizeof(double) - 1;
//    set_f_sign(input, ptr, len);
//    /* base �Ϲ������� �� �д� ����� ���� �� */
//    n = read_exponent(ptr, len);
//    make_floating(d, ptr, n, len);
//
//}
//
//int				set_f_input(double n)
//{
//    t_input* input;
//    char* str;
//    char* ptr;
//    int		size;
//
//    if (!(input = (t_input*)(malloc(sizeof(t_input)))))
//        return (0);
//    g_info->input = input;
//    ptr = (char*)&n;
//    read_floating(input, n, ptr);
//
//
//    // �������ؼ� �ؼ� �ڸ��� �Ǵ��ѱ�.
//
//    // ��ȣ��Ʈ Ȯ��
//
//    // ������Ʈ Ȯ��
//    /*
//        1. ������Ʈ�� ���� 0~51�� ���, ���� �Ǽ� ���� �����ϴϱ� bit�ؼ��ϸ� ��.
//        2. ������Ʈ�� ���� 52�̻��� ���, �ش簪�� ������.
//            2-1) �̶� �Ҽ����� �ٻ簪������ ���̳����� 0���θ� ����Ѵ�.
//            2-2) ��� �������� ����� �� �� �ִ°�?
//                �� 1001.000000 �̶��?
//                �� /10���ϸ�, 100.1 ��. �Ҽ��� .1�� ����ϰ� ������ ��.
//                �� �׷��ٸ�, 100.1 - 100 �� ����� 0.1xxxx �ɲ���..
//                �� �̰Ÿ� �ٽ� 10 ���ϸ�, 1.xxxx �ɲ��ϱ�.. ���⼭ 1�� ����
//                �� �̰� �ݺ�..
//        3. ������Ʈ�� ���� 0�̸��� ���, �ش� ���� 0.xxxxx �̴�.
//            3-1) �Ǽ��θ� ����Ѵ�.
//                �� HOW ?
//                �� �̰�.. �׳� �����δ� [0.] ���̰�, precision_len�� ������ 6�ڸ���, ������ precision_len ��ŭ �ݺ��ؼ� ����.
//    */
//
//
//
//
//    //size = setlen_f(input, n);
//    //if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
//    //	return (0);
//    //input->str = str;
//    //str[size--] = 0;
//    //fill_str_f(input, n, size);
//    return (0);
//}