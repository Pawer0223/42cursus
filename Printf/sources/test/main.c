#include "../../headers/printf.h"
#include <limits.h>
#include <math.h>

void    sprintf_test()
{
    double n = 1.2345;
    char buf[10];
    sprintf(buf, "%f", n);
}

void	di_test()
{
    printf("######### di test #########\n");
    printf("### 1 ###\n");
    printf   ("%%-.10d :[%-.10d]\n", 12345);
    ft_printf("%%-.10d :[%-.10d]\n", 12345);
    // printf("%%020.10d :[%020.10d]\n", 12345); // warning
    printf("### 2 ###\n");
    printf   ("%%010d :[%010d]\n", 12345);
    ft_printf("%%010d :[%010d]\n", 12345);
    // printf("%%010.1d :[%010.1d]\n", 12345); // warning
    printf("### 3 ###\n");
    printf   ("%%10d :[%10d]\n", 12345);
    ft_printf("%%10d :[%10d]\n", 12345);
    printf("### 4 ###\n");
    printf   ("%%010d :[%010d]\n", 12345);
    ft_printf("%%010d :[%010d]\n", 12345);
    printf("### 5 ###\n");
    printf   ("%%3.10d :[%3.10d]\n", 12345);
    ft_printf("%%3.10d :[%3.10d]\n", 12345);
    printf("### 6 ###\n");
    printf   ("%%10.3d :[%10.3d]\n", 12345);
    ft_printf("%%10.3d :[%10.3d]\n", 12345);
    printf("### 7 ###\n");
    printf   ("%%3.3d :[%3.3d]\n", 12345);
    ft_printf("%%3.3d :[%3.3d]\n", 12345);
    printf("### 8 ###\n");
    printf   ("%%d :[%d]\n", 12345);
    ft_printf("%%d :[%d]\n", 12345);
    printf("### 9 ###\n");
    printf   ("%% d :[% d]\n", 12345);
    ft_printf("%% d :[% d]\n", 12345);
    printf("### 10 ###\n");
    printf   ("%%+d :[%+d]\n", 12345);
    ft_printf("%%+d :[%+d]\n", 12345);
    printf("### 11 ###\n");
    printf   ("%%+d :[%+d]\n", +123);
    ft_printf("%%+d :[%+d]\n", +123);
    printf("### 12 ###\n");
    printf   ("%%+d :[%+d]\n", -123);
    ft_printf("%%+d :[%+d]\n", -123);
    printf("### 13 ###\n");
    printf   ("%%10.5d :[%10.5d]\n", 123);
    ft_printf("%%10.5d :[%10.5d]\n", 123);
    printf("### 14 ###\n");
    printf   ("%%03d =>[%03d]\n", 0);
    ft_printf("%%03d =>[%03d]\n", 0);
    printf("### 15 ###\n");
    printf   ("%%.3d =>[%.3d]\n", 0);
    ft_printf("%%.3d =>[%.3d]\n", 0);
    // printf("### 16 ###\n");
    // printf   ("%%i =>[%i]\n", INT_MAX + 100);
    // ft_printf("%%i =>[%i]\n", INT_MAX + 100);
    printf("### 17 ###\n");
    printf("%%d =>[%d]\n", UINT_MAX);
    ft_printf("%%d =>[%d]\n", UINT_MAX);
    printf("### 18 ###\n");
    printf   ("%%.d =>[%.d]\n", 0);
    ft_printf("%%.d =>[%.d]\n", 0);
    printf("### 19 ###\n");
    printf   ("%%.d =>[%.d]\n", 1);
    ft_printf("%%.d =>[%.d]\n", 1);
    printf("### 20 ###\n");
    printf   ("%%d => [%d]\n", 0);
    ft_printf("%%d => [%d]\n", 0);
    printf("### 21 ###\n");
    printf   ("%%0d => [%0d]\n", 0);
    ft_printf("%%0d => [%0d]\n", 0);
    printf("### 22 ###\n");
    printf   ("%%.d => [%.d]\n", 0);
    ft_printf("%%.d => [%.d]\n", 0);
    printf("### 23 ###\n");
    printf   ("%%10.d => [%10.d]\n", 0);
    ft_printf("%%10.d => [%10.d]\n", 0);
    printf("### 24 ###\n");
    printf   ("%%.0d => [%.0d]\n", 0);
    ft_printf("%%.0d => [%.0d]\n", 0);
    printf("### 25 ###\n");
    printf   ("%%.3d => [%.3d]\n", 0);
    ft_printf("%%.3d => [%.3d]\n", 0);
    printf("### 26 ###\n");
    printf   ("%%.1d => [%.1d]\n", 0);
    ft_printf("%%.1d => [%.1d]\n", 0);
    printf("### 27 ###\n");
    printf   ("%% d => [% d]\n", 0);
    ft_printf("%% d => [% d]\n", 0);
    printf("### 28 ###\n");
    printf   ("%%-d => [%-d]\n", 0);
    ft_printf("%%-d => [%-d]\n", 0);
    printf("### 29 ###\n");
    printf   ("%%+d => [%+d]\n", 0);
    ft_printf("%%+d => [%+d]\n", 0);
    printf("### 30 ###\n");
    printf   ("%%+.d => [%+.d]\n", 0);
    ft_printf("%%+.d => [%+.d]\n", 0);

        printf("1 => [%hhd]\n", (char)46);
    ft_printf("2 => [%hhd]\n", (char)46);

    printf("1 => [%d]\n", (char)46);
    ft_printf("2 => [%d]\n", (char)46);

}

void    u_test()
{
    unsigned int a = UINT_MAX;
    printf("######### u test #########\n");
    printf("### 1 ###\n");
    printf   ("%%u =>[%u]\n", a);
    ft_printf("%%u =>[%u]\n", a);
    printf("### 2 ###\n");
    printf   ("%%20u =>[%20u]\n", a);
    ft_printf("%%20u =>[%20u]\n", a);
    printf("### 3 ###\n");
    printf   ("%%.20u =>[%.20u]\n", a);
    ft_printf("%%.20u =>[%.20u]\n", a);
    printf("### 4 ###\n");
    printf   ("%%15.20u =>[%15.20u]\n", a);
    ft_printf("%%15.20u =>[%15.20u]\n", a);
    printf("### 5 ###\n");
    printf   ("%%20.15u =>[%20.15u]\n", a);
    ft_printf("%%20.15u =>[%20.15u]\n", a);
    printf("### 6 ###\n");
    printf   ("%%u =>[%u]\n", -10);
    ft_printf("%%u =>[%u]\n", -10);
    printf("### 7 ###\n");
    printf   ("%% u =>[% u]\n", +123);
    ft_printf("%% u =>[% u]\n", +123);
    printf("### 8 ###\n");
    printf   ("%%+u =>[%+u]\n", -456);
    ft_printf("%%+u =>[%+u]\n", -456);
    printf("### 9 ###\n");
    printf   ("%%-10u =>[%-10u]\n", 0);
    ft_printf("%%-10u =>[%-10u]\n", 0);
    printf("### 10 ###\n");
    printf   ("%%5.3u =>[%5.3u]\n", 0);
    ft_printf("%%5.3u =>[%5.3u]\n", 0);
    printf("### 11 ###\n");
    printf("%%.u =>[%.u]\n", 0);
    ft_printf("%%.u =>[%.u]\n", 0);
    printf("### 12 ###\n");
    printf("%%.u =>[%.u]\n", 1);
    ft_printf("%%.u =>[%.u]\n", 1);
    printf("### 13 ###\n");
    printf("%%u => [%u]\n", 0);
    ft_printf("%%u => [%u]\n", 0);
    printf("### 14 ###\n");
    printf("%%0u => [%0u]\n", 0);
    ft_printf("%%0u => [%0u]\n", 0);
    printf("### 15 ###\n");
    printf("%%.u => [%.u]\n", 0);
    ft_printf("%%.u => [%.u]\n", 0);
    printf("### 16 ###\n");
    printf("%%10.u => [%10.u]\n", 0);
    ft_printf("%%10.u => [%10.u]\n", 0);
    printf("### 17 ###\n");
    printf("%%.0u => [%.0u]\n", 0);
    ft_printf("%%.0u => [%.0u]\n", 0);
    printf("### 18 ###\n");
    printf("%%.3u => [%.3u]\n", 0);
    ft_printf("%%.3u => [%.3u]\n", 0);
    printf("### 19 ###\n");
    printf("%%.1u => [%.1u]\n", 0);
    ft_printf("%%.1u => [%.1u]\n", 0);
    printf("### 20 ###\n");
    printf("%% u => [% u]\n", 0);
    ft_printf("%% u => [% u]\n", 0);
    printf("### 21 ###\n");
    printf("%%-u => [%-u]\n", 0);
    ft_printf("%%-u => [%-u]\n", 0);
    printf("### 22 ###\n");
    printf("%%+u => [%+u]\n", 0);
    ft_printf("%%+u => [%+u]\n", 0);
    printf("### 23 ###\n");
    printf("%%+.u => [%+.u]\n", 0);
    ft_printf("%%+.u => [%+.u]\n", 0);
    printf("### 24 ###\n");
    printf   ("%%u =>[%u], %%20u =>[%20u], %%.20u =>[%.20u], %%15.20u =>[%15.20u], %%20.15u =>[%20.15u], %%u =>[%u], %% u =>[% u], %%+u =>[%+u], %%-10u =>[%-10u], %%5.3u =>[%5.3u]\n", a, a, a, a, a, -10, +123, -456, 0, 0);
    ft_printf("%%u =>[%u], %%20u =>[%20u], %%.20u =>[%.20u], %%15.20u =>[%15.20u], %%20.15u =>[%20.15u], %%u =>[%u], %% u =>[% u], %%+u =>[%+u], %%-10u =>[%-10u], %%5.3u =>[%5.3u]\n", a, a, a, a, a, -10, +123, -456, 0, 0);

}

void    x_test()
{
    printf("######### x test #########\n");
    printf("### 1 ###\n");
    printf   ("%%x =>[%x]\n", 10);
    ft_printf("%%x =>[%x]\n", 10);
    printf("### 2 ###\n");
    printf   ("%% x =>[% x]\n", 10);
    ft_printf("%% x =>[% x]\n", 10);
    printf("### 3 ###\n");
    printf   ("%%+x =>[%+x]\n", 10);
    ft_printf("%%+x =>[%+x]\n", 10);
    printf("### 4 ###\n");
    printf   ("%%5.3x =>[%5.3x]\n", 10);
    ft_printf("%%5.3x =>[%5.3x]\n", 10);
    printf("### 5 ###\n");
    printf   ("%%#x =>[%#x]\n", 10);
    ft_printf("%%#x =>[%#x]\n", 10);
    printf("### 6 ###\n");
    printf   ("%%#5x =>[%#5x]\n", 10);
    ft_printf("%%#5x =>[%#5x]\n", 10);
    printf("### 7 ###\n");
    printf   ("%%#.5x =>[%#.5x]\n", 10);
    ft_printf("%%#.5x =>[%#.5x]\n", 10);
    printf("### 8 ###\n");
    printf   ("%%#.5X =>[%#.5X]\n", 10);
    ft_printf("%%#.5X =>[%#.5X]\n", 10);
    printf("### 9 ###\n");
    printf   ("%%#X =>[%#X]\n", -1);
    ft_printf("%%#X =>[%#X]\n", -1);
    printf("### 10 ###\n");
    printf   ("%%20.50x =>[%#.5x]\n", UINT_MAX);
    ft_printf("%%20.50x =>[%#.5x]\n", UINT_MAX);
    printf("### 11 ###\n");
    printf   ("%%#x =>[%#x]\n", UINT_MAX + 1);
    ft_printf("%%#x =>[%#x]\n", UINT_MAX + 1);
    printf("### 12 ###\n");
    printf("%%.x =>[%.x]\n", 0);
    ft_printf("%%.x =>[%.x]\n", 0);
    printf("### 13 ###\n");
    printf("%%.x =>[%.x]\n", 1);
    ft_printf("%%.x =>[%.x]\n", 1);
    printf("### 14 ###\n");
    printf("%%x => [%x]\n", 0);
    ft_printf("%%x => [%x]\n", 0);
    printf("### 15 ###\n");
    printf("%%0x => [%0x]\n", 0);
    ft_printf("%%0x => [%0x]\n", 0);
    printf("### 16 ###\n");
    printf("%%.x => [%.x]\n", 0);
    ft_printf("%%.x => [%.x]\n", 0);
    printf("### 17 ###\n");
    printf("%%10.x => [%10.x]\n", 0);
    ft_printf("%%10.x => [%10.x]\n", 0);
    printf("### 18 ###\n");
    printf("%%.0x => [%.0x]\n", 0);
    ft_printf("%%.0x => [%.0x]\n", 0);
    printf("### 19 ###\n");
    printf("%%.3x => [%.3x]\n", 0);
    ft_printf("%%.3x => [%.3x]\n", 0);
    printf("### 20 ###\n");
    printf("%%.1x => [%.1x]\n", 0);
    ft_printf("%%.1x => [%.1x]\n", 0);
    printf("### 21 ###\n");
    printf("%% x => [% x]\n", 0);
    ft_printf("%% x => [% x]\n", 0);
    printf("### 22 ###\n");
    printf("%%-x => [%-x]\n", 0);
    ft_printf("%%-x => [%-x]\n", 0);
    printf("### 23 ###\n");
    printf("%%+x => [%+x]\n", 0);
    ft_printf("%%+x => [%+x]\n", 0);
    printf("### 24 ###\n");
    printf("%%+.x => [%+.x]\n", 0);
    ft_printf("%%+.x => [%+.x]\n", 0);

}
void        test_lc()
{
    wchar_t ws1[20] = L"Hello, world!";
    wprintf(L"%d\n", wcslen(ws1));
    wprintf(L"%S\n", ws1);
}

void        c_test()
{
    printf("######### c test #########\n");
    for (int i = 1; i < 257; i++)
    {
        if (i == 27) // 27은 esc라서 종료 되네..
            continue;
        printf("### %d ###\n",i);
        printf("[%c]\n", i);
        ft_printf("[%c]\n", i);
    }

    printf("### etc 1 ###\n");
     printf("%%c =>[%+10.c]\n", 'b');
     ft_printf("%%c =>[%+10.c]\n", 'b');
     printf("### etc 2 ###\n");
     printf("%%-10.c =>[%-10.c]\n", 'b');
     ft_printf("%%-10.c =>[%-10.c]\n", 'b');
     printf("### etc 3 ###\n");
     printf("%%10.c =>[%#10.c]\n", 'b');
     ft_printf("%%10.c =>[%#10.c]\n", 'b');
     printf("### etc 4 ###\n");
     printf("%% 10c =>[% 10.c]\n", 'b');
     ft_printf("%% 10c =>[% 10.c]\n", 'b');
     printf("### etc 5 ###\n");
     printf("%%.100c =>[%-.100c]\n", 'b');
     ft_printf("%%.100c =>[%-.100c]\n", 'b');
     printf("### etc 6 ###\n");
     printf("%%c =>[%c]\n", 256);
     ft_printf("%%c =>[%c]\n", 256);

     printf("### etc7 ###\n");
     printf("[%5c]\n", '\x00');
     ft_printf("[%5c]\n", '\x00');

}

void        s_test()
{
    printf("######### s test #########\n");
    printf("### 1 ###\n");
    printf("%%s =>[%s]\n", "안녕하세요");
    ft_printf("%%s =>[%s]\n", "안녕하세요");
    printf("### 2 ###\n");
    printf("%%.2s =>[%10.1s]\n", "abcdefg");
    ft_printf("%%.2s =>[%10.1s]\n", "abcdefg");
    printf("### 3 ###\n");
    printf("%%10.5s =>[%10.5s]\n", "123456789");
    ft_printf("%%10.5s =>[%10.5s]\n", "123456789");
    printf("### 4 ###\n");
    printf("%%.s =>[%.s]\n", "abc");
    ft_printf("%%.s =>[%.s]\n", "abc");
    printf("### 5 ###\n");
    printf("%%10.s =>[%10.s]\n", "defg");
    ft_printf("%%10.s =>[%10.s]\n", "defg");

    int a = ft_printf("hello, %s\n", NULL);
    printf("a => [%d]\n",a);
    a = ft_printf("hello, %.s\n", NULL);
    printf("a => [%d]\n",a);
    a = ft_printf("%32s\n", NULL);
    printf("a => [%d]\n",a);
    a = ft_printf("%.03s\n", NULL);
    printf("a => [%d]\n",a);

    char *str = "hi low";
    printf("%00-s\n", str);
    ft_printf("%00-s\n", str);

    printf("%.*s\n", -3, "hello");
    ft_printf("%.*s\n", -3, "hello");

    printf("%.*i\n", -6, -3);
    ft_printf("%.*i\n", -6, -3);

    printf("1 [%.*s]\n", -3, 0);
    ft_printf("2 [%.*s]\n", -3, 0);

        printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
    ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");

    printf("%.*s\n", 3, "hello");
    ft_printf("%.*s\n", 3, "hello");

        a = printf("[%*s]", -32, "abc");
        printf("\n a = >[%d]\n", a);

        a = ft_printf("[%*s]", -32, "abc");
        printf("\n a = >[%d]\n", a);

        a = printf("[%.*s]", -3, "hello");
        printf("\n a = >[%d]\n", a);

        a = ft_printf("[%.*s]", -3, "hello");
        printf("\n a = >[%d]\n", a);

        a = printf("[%.s]", "hello");
        printf("\n a = >[%d]\n", a);

        a = ft_printf("[%.s]", "hello");
        printf("\n a = >[%d]\n", a);

        a = printf("this %s is empty\n", "");
        printf("a = >[%d]\n", a);
        a = ft_printf("this %s is empty\n", "");
        printf("a = >[%d]\n", a);

        char * s_hidden = "hi low";
        a = printf("%0000s\n", s_hidden);
        printf("a = >[%d]\n", a);
        a = ft_printf("%0000s\n", s_hidden);
        printf("a = >[%d]\n", a);
    }

void        p_test()
{
    printf("######### p test #########\n");

    // 32비트는 4, 64비트는 8로 표현.
    // 즉 사용할 수 있는 메모리 공간의 크기가 64비트가 훨씬많음

    // 32비트는 주소가 최대 16진수 8자리
    // 64비트는 주소가 최대 16진수 16자리로 표현 가능하다.
    // because 1바이트는 2개의 16진수를 표현할 수 있으니깐.
    int a = 0;
    unsigned long long num = (unsigned long long) & a;

    printf("address size : %ld\n", sizeof(&a));
    printf("서식지정자 p는 linux에서  높은 자릿수의 0은 생략 008AF7FC는 0x8af7fc 와같이\n");
    printf("### 1 ###\n");
    printf("%%p =>[%p], %%lld =>[%lld]\n", &a, num);
    ft_printf("%%p =>[%p], %%lld =>[%lld]\n", &a, num);
    printf("### 2 ###\n");
    printf("%%-20p =>[%-20p]\n", &a);
    ft_printf("%%-20p =>[%-20p]\n", &a);
    printf("### 3 ###\n");
    printf("%%20p =>[%20p]\n", &a);
    ft_printf("%%20p =>[%20p]\n", &a);
    printf("### 4 ###\n");
    printf("%%.5p =>[%.5p]\n", &a);
    ft_printf("%%.5p =>[%.5p]\n", &a);
    printf("### 5 ###\n");
    printf("%% p =>[% p]\n", &a);
    ft_printf("%% p =>[% p]\n", &a);
    printf("### 6 ###\n");
    printf("%%+p =>[%+p]\n", &a);
    ft_printf("%%+p =>[%+p]\n", &a);
    printf("### 7 ###\n");
    printf("%%#p =>[%#p]\n", &a);
    ft_printf("%%#p =>[%#p]\n", &a);
    printf("### 8 ###\n");
    printf("%%p =>[%p]\n", -1);
    ft_printf("%%p =>[%p]\n", -1);
    printf("### 9 ###\n");
    printf("%%p =>[%p]\n", 0);
    ft_printf("%%p =>[%p]\n", 0);
    printf("### 10 ###\n");
    printf("%%p =>[%10p]\n", 0);
    ft_printf("%%p =>[%10p]\n", 0);
    printf("### 11 ###\n");
    printf("%%.3p =>[%.3p]\n", 256);
    ft_printf("%%.3p =>[%.3p]\n", 256);
    printf("### 12 ###\n");
    printf("%.5p\n", 0);
    ft_printf("%.5p\n", 0);
    printf("### 13 ###\n");
    printf("%.*p\n", -3, 0);
    ft_printf("%.*p\n", -3, 0);
}

void        n_test()
{
    printf("######### n test #########\n");
    int num;
    char c;
    printf("### 1 ###\n");
    printf("123%n6789\n", &num); // 123456789
    ft_printf("123%n6789\n", &num); // 123456789
    printf("### 2 ###\n");
    printf("num : %d\n", num); // 3 , 123까지 출력했응께
    ft_printf("num : %d\n", num); // 3 , 123까지 출력했응께
    printf("### 3 ###\n");
    printf("a%n\n", &num); // 123456789
    ft_printf("a%n\n", &num); // 123456789
    printf("### 4 ###\n");
    printf("num : %d\n", num); // 5 , a출력
    ft_printf("num : %d\n", num); // 5 , a출력
    printf("### 5 ###\n");
    printf("ㄱ밥%n6789\n", &num); // 16789
    ft_printf("ㄱ밥%n6789\n", &num); // 16789
    printf("### 6 ###\n");
    printf("num : %d\n", num); // 1
    ft_printf("num : %d\n", num); // 1
    printf("### 7 ###\n");
    printf("0%hhn6789\n", &c);
    ft_printf("0%hhn6789\n", &c);
    printf("### 8 ###\n");
    printf("0123456789%hhn6789\n", &num);
    ft_printf("0123456789%hhn6789\n", &num);
    printf("### 9 ###\n");
    printf("num : %d\n", num);
    ft_printf("num : %d\n", num);
    printf("### 10 ###\n");
    printf("c : %d\n", c);
    ft_printf("c : %d\n", c);
    int n1;
    int n2;
    int n3;
    printf("### 11 ###\n");
    printf("a%n,ab%n,abc%n\n", &n1, &n2, &n3);
    ft_printf("a%n,ab%n,abc%n\n", &n1, &n2, &n3);
    printf("### 12 ###\n");
    printf("n1 :%d, n2:%d, n3:%d\n", n1, n2, n3);
    ft_printf("n1 :%d, n2:%d, n3:%d\n", n1, n2, n3);
    int n4;
    printf("### 13 ###\n");
    printf("abcd%d%d%n\n", 100, 2000, &n4);
    ft_printf("abcd%d%d%n\n", 100, 2000, &n4);
    printf("### 14 ###\n");
    printf("n4 is %d\n", n4);
    ft_printf("n4 is %d\n", n4);
    printf("### 15 ###\n");
    printf("abcd%20.10d%d%n\n", 100, 2000, &n4);
    ft_printf("abcd%20.10d%d%n\n", 100, 2000, &n4);
    printf("### 16 ###\n");
    printf("n4 is %d\n", n4);
    ft_printf("n4 is %d\n", n4);
    printf("### 17 ###\n");
    printf("[%5%]\n");
    ft_printf("[%5%]\n");
    printf("### 18 ###\n");
    printf("[%5%]\n");
    ft_printf("[%5%]\n");
    printf("### 19 ###\n");
    printf("[%-5%]\n");
    ft_printf("[%-5%]\n");
    printf("### 20 ###\n");
    printf("[%05%]\n");
    ft_printf("[%05%]\n");
    printf("### 21 ###\n");
    printf("[% 5%]\n");
    ft_printf("[% 5%]\n");
    printf("### 22 ###\n");
    printf("[%-05%]\n");
    ft_printf("[%-05%]\n");

    printf("%.6i\n", -3);
    ft_printf("%.6i\n", -3);

    printf("%.6i\n", 100);
    ft_printf("%.6i\n", 100);

    printf("%03i\n", -543215);
    ft_printf("%03i\n", -543215);

    printf("%7i\n", 33);
    ft_printf("%7i\n", 33);

    printf("%10.3d\n", -12);
    ft_printf("%10.3d\n", -12);


    printf("%07i\n", -54);
    ft_printf("%07i\n", -54);

    int a = 22;
    printf("%07i\n", -a);
    ft_printf("%07i\n", -a);
    printf("% 7i\n", -a);
    ft_printf("% 7i\n", -a);
    printf("%+7i\n", -a);
    ft_printf("%+7i\n", -a);

}

void        test_one_bit_oper()
{

    for (int i = 0; i < 10; i++) {
       // printf("%d\n", 1 << i);
         printf("1 << %d => %d\n", i, (1 << i)); // 1은 00001이다 왼쪽으로 1bit씩 옮기면서 &연산을통해 해당 bit의 수를 알아낼 수 있다.
    }
}

void        x_bit_test()
{
    long long  a = 100;

    char* ptr;

    ptr = (char*)&a;

    for (int i = 0; i < sizeof(long long); i++) {
        char n = *(ptr + i);
        printf("%d byte hexa value : %d\n", i + 1, n);
    }

    printf("%x\n", a);
}

void        float_bit_test()
{
    float d = 10.0f;

    unsigned char* ptr;
    ptr = (unsigned char*)&d;
    int j = 0;
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        //for (int j = 0; j < 8; j++)
        //{
        //    printf("%d", (*(ptr + i) >> j) & dif);
        //}
        for (j = 7; j >= 0; j--)
            printf("%d", (*(ptr + i) >> j) & 0x01); // 8765 4321 이렇게 있으면 8을 1로보내서 1하고 & 연산 함.
        printf(" ");
    }

    /*
        unsigned int ptr;
        ptr = &d;
        ptr = *(unsigned int *)&d;
        printf("ptr is : %d\n", ptr);
        int size = sizeof(float);

        for (int i = size * 8 - 1; i >= 0; i--) {
            printf("%d", (ptr & (1 << i)) ? 1 : 0);
            if (i % 8 == 0)
                printf(" ");
        }
      */

    //long long temp;
    //temp = d;
    //// fail case
    //printf("\n#Fail Case 1, just Temp : %ld\n", temp); // 값이 저장 됨.
    //for (int i = size * 8 - 1; i >= 0; i--) {
    //    printf("%d", (temp & (1 << i)) ? 1 : 0);
    //    if (i % 8 == 0)
    //        printf(" ");
    //}
    //temp = &d;
    //printf("\nFail Case 2, Temp Addres Save.. : %ld\n", temp); // 얘도 주소를 해석하는듯..
    //for (int i = size * 8 - 1; i >= 0; i--) {
    //    printf("%d", (temp & (1 << i)) ? 1 : 0);
    //    if (i % 8 == 0)
    //        printf(" ");
    //}

    //temp = (unsigned int*)&d;
    //printf("\nFail Case 3, Temp Addres Save.. with Type Promotion : %ld\n", temp); // 얘도 2랑 차이없네.
    //for (int i = size * 8 - 1; i >= 0; i--) {
    //    printf("%d", (temp & (1 << i)) ? 1 : 0);
    //    if (i % 8 == 0)
    //        printf(" ");
    //}

    //temp = *(long long*)&d;
    //printf("\nnFail Case 4, Type Promotion and reverse ref: %ld\n", temp); // 얘도 안되네...
    //for (int i = size * 8 - 1; i >= 0; i--) {
    //    printf("%d", (temp & (1 << i)) ? 1 : 0);
    //    if (i % 8 == 0)
    //        printf(" ");
    //}


    //for (int i = size; i > 0; i--) // 몇 byte인지
    //{
    //    for (int j = i * 8 - 1; j >= (i - 1) * 8; j--) // 1byte에 해당하는 이진수 출력
    //    {
    //        printf("%d", (ptr & (1 << j)) ? 1 : 0);
    //    }
    //    printf(" ");
    //}

    /*for (int i = sizeof(float) - 1; i >= 0; i--) {
        printf("%x , %d\n", *(ptr + i), *(ptr + i));
    }*/

    //printf("a is %f, b is %f\n", a , b);
}

void        double_bit_test2(double a)
{
    printf("Input : [%f]\n", a);

    unsigned char* ptr;
    ptr = (unsigned char*)&a;

    // sign bit , 1
    // exponent , 11
    // mantissa , 52
    int bias = 1023;

    int len = sizeof(double) - 1;
    int sign;
    int j;

    sign = ((*(ptr + len) >> 7) & 0x01) == 0 ? 1 : -1;

    int expoCnt = 10;
    int n = 0;
    // 8, 7 byte에서 sign과 exponent 추출
    // 지수에 해당하는 n 구하기.
    for (int i = len; i >= len - 1; i--) {
        for (j = 7; j >= 0; j--) {
            if (i == len && j == 7)
                continue;
            int bit = (*(ptr + i) >> j) & 0x01;
            if (bit == 1)
                n += pow(2, expoCnt);
            expoCnt--;
            if (expoCnt == -1)
                break;
        }
    }
    printf("sign : [%d]\n", sign);
    printf("n : [%d - %d]\n",n, bias);
    printf("j : %d\n", j);
    n -= bias;
    j--;

    double mantissa = 1;
    int matCnt = -1;
    int cnt = 0;
    // mantissa 추출하기
    for (int i = len - 1; i >= 0; i--) {
        for (int k = j; k >= 0; k--) {
            int bit = (*(ptr + i) >> k) & 0x01;
            if (bit == 1)
                mantissa += pow(2, matCnt);
            matCnt--;
            cnt++;
        }
        j = 7;
    }
    printf("cnt is %d \n", cnt);
    printf("mantissa : %f , cnt .. %d\n", mantissa, matCnt);
    double result = sign * pow(2, n) * mantissa;
    printf("result is : %f\n", result);
    printf("result %%.300f is : %.300f\n", result);
    printf("origin %%.300f is : %.300f\n", a);
}

void        double_bit_test(double a)
{
    //double test = pow(2, -52);
    //printf("test : [%.20e]\n", test);
    printf("### bit Check Start ### \n");
    unsigned char* ptr;
    ptr = (unsigned char*)&a;
    int j = 0;
    for (int i = sizeof(double) - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            printf("%d", (*(ptr + i) >> j) & 0x01); // 8765 4321 이렇게 있으면 8을 1로보내서 1하고 & 연산 함.
        }
        printf(" ");
    }
    printf("\n### bit Check End ### \n");
}

void    round_test()
{
    double a = 0.120;
    double b = 0.130;

    printf("0.125 와 0.135의 차이점 확인\n");
    printf("### 1 ###\n");
    for (int i = 0; i < 10; i++)
    {
        a += 0.001;
        printf("================[%d]===============\n",i);
        printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
        ft_printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
    }

    printf("### 2 ###\n");
    for (int i = 0; i < 10; i++)
    {
        b += 0.001;
        printf("================[%d]===============\n", i);
        printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
        ft_printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
    }
    printf("3~4 왜 7.125에서 차이가 나지... \n");

    printf("### 3 ###\n");
    a = 0.125;
    for (int i = 0; i < 10; i++)
    {
        a += 1;
        printf("================[%d]===============\n", i);
        printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
        ft_printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
    }

    a = 7.120;
    printf("### 4 ###\n");
    for (int i = 0; i < 10; i++)
    {
        a += 0.001;
        printf("================[%d]===============\n", i);
        printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
        ft_printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
    }

    b = 7.130;
    printf("### 5 ###\n");
    for (int i = 0; i < 10; i++)
    {
        b += 0.001;
        printf("================[%d]===============\n", i);
        printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
        ft_printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
    }


    printf("### 6 ###\n");
    a = 0.5;
    b = 0.51;
    for (int i = 0; i < 10; i++)
    {
        a += 1;
        b += 1;
        printf("================[%d]===============\n", i);
        printf("###### a #####\n");
        printf("%%f => [%f], %%.f => [%.f]\n", a, a);
        ft_printf("%%f => [%f], %%.f => [%.f]\n", a, a);
        printf("###### b #####\n");
        printf("%%f => [%f], %%.f => [%.f]\n", b, b);
        ft_printf("%%f => [%f], %%.f => [%.f]\n", b, b);
    }
}


void        f_test()
{
    printf("######### f test #########\n");

    double a = -123.45;
    double b = 0.6789;
    printf("### 1 ###\n");
    printf("%%.3f=>[%.3f]\n", a);
    ft_printf("%%.3f=>[%.3f]\n", a);
    printf("### 2 ###\n");
    printf("%%.5f=>[%.5f]\n", a);
    ft_printf("%%.5f=>[%.5f]\n", a);
    printf("### 3 ###\n");
    printf("%%.f=>[%.f]\n", a);
    ft_printf("%%.f=>[%.f]\n", a);
    printf("### 4 ###\n");
    printf("%%.0f=>[%.0f]\n", a);
    ft_printf("%%.0f=>[%.0f]\n", a);

    // printf("%%.-5f=>[%.-5f]\n", a); // error
    printf("### 5 ###\n");
    printf("%% f=>[% f]\n", b);
    ft_printf("%% f=>[% f]\n", b);
    printf("### 6 ###\n");
    printf("%%+f=>[%+f]\n", b);
    ft_printf("%%+f=>[%+f]\n", b);
    printf("### 7 ###\n");
    printf("%%-10f=>[%-10f]\n", b);
    ft_printf("%%-10f=>[%-10f]\n", b);
    printf("### 8 ###\n");
    printf("%%20.10f=>[%20.10f]\n", b);
    ft_printf("%%20.10f=>[%20.10f]\n", b);

    double c = 0;

    printf("### 9 ###\n");
    printf("%% f=>[% f]\n", c);
    ft_printf("%% f=>[% f]\n", c);
    printf("### 10 ###\n");
    printf("%%+f=>[%+f]\n", c);
    ft_printf("%%+f=>[%+f]\n", c);
    printf("### 11 ###\n");
    printf("%%-10f=>[%-10f]\n", c);
    ft_printf("%%-10f=>[%-10f]\n", c);
    printf("### 12 ###\n");
    printf("%%20.10f=>[%20.10f]\n", c);
    ft_printf("%%20.10f=>[%20.10f]\n", c);
    printf("### 13 ###\n");
    printf("%%.f=>[%.f]\n", c);
    ft_printf("%%.f=>[%.f]\n", c);
    printf("### 14 ###\n");
    printf("%%.1f=>[%.1f]\n", c);
    ft_printf("%%.1f=>[%.1f]\n", c);
    printf("### 15 ###\n");
    printf("%%10.0f=>[%10.0f]\n", c);
    ft_printf("%%10.0f=>[%10.0f]\n", c);
}

void    big_test()
{
    printf("### 큰 숫자 정수를 나타낼 때, 범위가 생각보다 크다(최소 2^10이상 까지 같은 정수로 인식 하는것을 확인 함..)\n");
    double a = (double)LLONG_MAX;
    int addNum = 0;

    double prev;
    printf("### 1 ###\n");
    for (int i = 0; i < 61; i++)
    {
        prev = a;
        addNum += 100;
        a += addNum;
        printf("[%lld + %d] ==> [%.10f] , -100 출력과 차이 값 ==> [%f]\n", LLONG_MAX, addNum, a, (a - prev));
    }
    printf("### 2 ###\n");
    a = (double)LLONG_MAX;
    addNum = 1000;
    for (int i = 0; i < 30; i++)
    {
        prev = a;
        addNum++;
        a += addNum;
        printf("[%lld + %d] ==> [%.10f] , -100 출력과 차이 값 ==> [%f]\n", LLONG_MAX, addNum, a, (a - prev));
    }
}

void    big_number_test()
{
    double a;
    double b;
    a = (double)LLONG_MAX;
    b = 0.12345678971234567897123456789712345678971234567897;

   double_bit_test(b);
   double_bit_test2(b);

    printf("a : %f\nb : %f \n", a, b);
}
// 정수와 실수를 분리하는 코드
double		separate_double(double d)
{
    printf("############### start [%f] ############\n", d);
    int cnt = 0;

    double d2 = d;
    while (d2 > 1)
    {
        d2 /= 10;
        cnt++;
    }
    printf("[%f] cnt is [%d]\n", d, cnt);
    int i = 0;
    double d3 = 0;
    while (cnt > 0)
    {
        d2 *= 10;
        // printf("(int)d2 => [%d]\n", (int)d2);
        d3 += (int)d2 * pow(10, --cnt);
        d2 -= (int)d2;
        i++;
    }
    double d4 = d - d3;
    printf("d3 is [%f] , d4 is [%f]\n", d3, d4);
    printf("############### end ############\n");
    return (0);
}

void round_test2()
{
    double a = 0.125;
    double b = 0.135;

    printf("##############################\n");
    printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
    ft_printf("%%f => [%f], %%.2f => [%.2f]\n", a, a);
    printf("##############################\n");
    printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
    ft_printf("%%f => [%f], %%.2f => [%.2f]\n", b, b);
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", a);
    ft_printf("%%.2f => [%.2f]\n", a);
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", b);
    ft_printf("%%.2f => [%.2f]\n", b);

    a = 0.125;
    a += 7;
    b = 7.120;
    b += 0.001;
    b += 0.001;
    b += 0.001;
    b += 0.001;
    b += 0.001;
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", a);
    ft_printf("%%.2f => [%.2f]\n",a);
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", b);
    ft_printf("%%.2f => [%.2f]\n", b);

    a = 0.999; // .1로하면 1.00나와야 함.
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", a);
    ft_printf("%%.2f => [%.2f]\n", a);

    a = 1.5;
    b = 1.51;
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);
    printf("##############################\n");
    printf("%%.f => [%.f]\n", b);
    ft_printf("%%.f => [%.f]\n", b);

    a = 0.5;
    b = 0.51;

    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);
    printf("##############################\n");
    printf("%%.f => [%.f]\n", b);
    ft_printf("%%.f => [%.f]\n", b);

    a = 9.51;
    printf("##############################\n");
    printf("%%.20f => [%.20f]\n", a);
    ft_printf("%%.20f => [%.20f]\n", a);
    printf("##############################\n");
    printf("%%.15f => [%.15f]\n", a);
    ft_printf("%%.15f => [%.15f]\n", a);
    printf("##############################\n");
    printf("%%.16f => [%.16f]\n", a);
    ft_printf("%%.16f => [%.16f]\n", a);
    printf("##############################\n");
    printf("%%.17f => [%.17f]\n", a);
    ft_printf("%%.17f => [%.17f]\n", a);
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);
    printf("##############################\n");
    printf("%%.1f => [%.1f]\n", a);
    ft_printf("%%.1f => [%.1f]\n", a);
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", a);
    ft_printf("%%.2f => [%.2f]\n", a);
    printf("##############################\n");
    printf("%%.3f => [%.3f]\n", a);
    ft_printf("%%.3f => [%.3f]\n", a);
    a = 0.125;
    printf("##############################\n");
    printf("%%.2f => [%.2f]\n", a);
    ft_printf("%%.2f => [%.2f]\n", a);

    a = -1.23456789;
    printf("##############################\n");
    printf("%%.15f => [%.15f]\n", a);
    ft_printf("%%.15f => [%.15f]\n", a);
    printf("##############################\n");
    printf("%%.16f => [%.16f]\n", a);
    ft_printf("%%.16f => [%.16f]\n", a);
    printf("##############################\n");
    printf("%%.17f => [%.17f]\n", a);
    ft_printf("%%.17f => [%.17f]\n", a);
    printf("##############################\n");
    printf("%%.18f => [%.18f]\n", a);
    ft_printf("%%.18f => [%.18f]\n", a);
    printf("##############################\n");
    printf("%%.19f => [%.19f]\n", a);
    ft_printf("%%.19f => [%.19f]\n", a);
    printf("##############################\n");
    printf("%%.100f => [%.100f]\n", a);
    ft_printf("%%.100f => [%.100f]\n", a);
    printf("##############################\n");
    printf("%%61.1f => [%61.1f]\n", a);
    ft_printf("%%61.1f => [%61.1f]\n", a);
    printf("##############################\n");
    printf("%%10.0f => [%10.0f]\n", a);
    ft_printf("%%10.0f => [%10.0f]\n", a);
    a = 2.5000000000000000;
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);

    a = 2.5000000000000010;
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);

    a = 2.5000000000000001;
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);

    a = 2.5000000000000000123456789123456789;
    printf("##############################\n");
    printf("%%.f => [%.f]\n", a);
    ft_printf("%%.f => [%.f]\n", a);

    a = 0.123456789712345;

    b = a * pow(10, 17);
    printf("%%.17f => [%.17f]\n", b);
    ft_printf("%%.17f => [%.17f]\n", b);
}

// 소수점 얼마나 정확하게 표현가능한지..
void    expo_test()
{
    // 1234567897 반복
    double a = 0.12345678971234567897123456789712345678971234567897;
    printf("##############################\n");
    printf("%%f => [%f]\n", a);
    ft_printf("%%f => [%f]\n", a);
    printf("##############################\n");
    printf("%%.10f => [%.10f]\n", a);
    ft_printf("%%.10f => [%.10f]\n", a);
    printf("##############################\n");
    printf("%%.20f => [%.20f]\n", a);
    ft_printf("%%.20f => [%.20f]\n", a);
    printf("##############################\n");
    printf("%%.30f => [%.30f]\n", a);
    ft_printf("%%.30f => [%.30f]\n", a);
    printf("##############################\n");
    printf("%%.40f => [%.40f]\n", a);
    ft_printf("%%.40f => [%.40f]\n", a);
    printf("##############################\n");
    printf("%%.50f => [%.50f]\n", a);
    ft_printf("%%.50f => [%.50f]\n", a);
    printf("##############################\n");
    printf("%%.60f => [%.60f]\n", a);
    ft_printf("%%.60f => [%.60f]\n", a);

    a = 5.12345678971234567897123456789712345678971234567897;

    printf("##############################\n");
    printf("%%.15f => [%.15f]\n", a);
    ft_printf("%%.15f => [%.15f]\n", a);
    printf("##############################\n");
    printf("%%.16f => [%.16f]\n", a);
    ft_printf("%%.16f => [%.16f]\n", a);
    printf("##############################\n");
    printf("%%.17f => [%.17f]\n", a);
    ft_printf("%%.17f => [%.17f]\n", a);
    printf("##############################\n");
    printf("%%.18f => [%.18f]\n", a);
    ft_printf("%%.18f => [%.18f]\n", a);
    printf("##############################\n");
    printf("%%.19f => [%.19f]\n", a);
    ft_printf("%%.19f => [%.19f]\n", a);
    printf("##############################\n");
    printf("%%.20f => [%.20f]\n", a);
    ft_printf("%%.20f => [%.20f]\n", a);
    printf("##############################\n");
    printf("%%.200f => [%.200f]\n", a);
    ft_printf("%%.200f => [%.200f]\n", a);
    printf("##############################\n");
    double d = 8888888888888.1;
    printf("%%.300f => [%.300f]\n", d);
    ft_printf("%%.300f => [%.300f]\n", d);
}

void    pft_test()
{
    static unsigned char  uch_pos_1 = 100;
    static unsigned short ush_pos_1 = 3047;
    static unsigned int     ui_pos_1 = 878023;
    static unsigned long  ul_pos_1 = 22337203685477;
    static unsigned long long   ull_pos_1 = 22337203685477;
    static unsigned long long  ullmax = 9223372036854775807;
    static unsigned long  ulmax = 9223372036854775807;
    printf("1 => [%llu%hhu%llu]\n", ull_pos_1, uch_pos_1, ull_pos_1);
    ft_printf("2 => [%llu%hhu%llu]\n", ull_pos_1, uch_pos_1, ull_pos_1);


    printf("1 => [%hu%lu%hhu]\n", ush_pos_1, ul_pos_1, uch_pos_1);
    ft_printf("2 => [%hu%lu%hhu]\n", ush_pos_1, ul_pos_1, uch_pos_1);

    printf("1 => [%lu%hhu%hu]\n", ul_pos_1, uch_pos_1, ush_pos_1);
    ft_printf("2 => [%lu%hhu%hu]\n", ul_pos_1, uch_pos_1, ush_pos_1);

    printf("1 => [%u%llu%hhu]\n", ui_pos_1, ull_pos_1, uch_pos_1);
    ft_printf("2 => [%u%llu%hhu]\n", ui_pos_1, ull_pos_1, uch_pos_1);

    printf("1 => [%llu%u%lu]\n", ull_pos_1, ui_pos_1, ul_pos_1);
    ft_printf("2 => [%llu%u%lu]\n", ull_pos_1, ui_pos_1, ul_pos_1);

    printf("1 => [%llu%hhu%llx]\n", ull_pos_1, uch_pos_1, ull_pos_1);
    ft_printf("2 => [%llu%hhu%llx]\n", ull_pos_1, uch_pos_1, ull_pos_1);

    printf("1 => [%hu%lu%hhx]\n", ush_pos_1, ul_pos_1, uch_pos_1);
    ft_printf("2 => [%hu%lu%hhx]\n", ush_pos_1, ul_pos_1, uch_pos_1);

    printf("1 => [%lu%hhu%hx]\n", ul_pos_1, uch_pos_1, ush_pos_1);
    ft_printf("2 => [%lu%hhu%hx]\n", ul_pos_1, uch_pos_1, ush_pos_1);

    printf("1 => [%u%llu%hhx]\n", ui_pos_1, ull_pos_1, uch_pos_1);
    ft_printf("2 => [%u%llu%hhx]\n", ui_pos_1, ull_pos_1, uch_pos_1);

    printf("1 => [%llu%u%lx]\n", ull_pos_1, ui_pos_1, ul_pos_1);
    ft_printf("2 => [%llu%u%lx]\n", ull_pos_1, ui_pos_1, ul_pos_1);

    printf("1 => [%#037lx]\n", 22337203685477ul);
    ft_printf("2 => [%#037lx]\n", 22337203685477ul);

    printf("1 => [% 010d]\n", 123);
    ft_printf("2 => [% 010d]\n", 123);

    printf("1 => [%+010d]\n", 123);
    ft_printf("2 => [%+010d]\n", 123);

    printf("1 => [%+010d]\n", 123);
    ft_printf("2 => [%+010d]\n", 123);


    printf("[%010x]\n", 43);
    ft_printf("[%010x]\n", 43);

    printf("[%010p]\n", 43);
    ft_printf("[%010p]\n", 43);

    printf("[%.*i]\n", -6, -3);
    ft_printf("[%.*i]\n", -6, -3);

    printf("1 => [%hu%lu%hhx]\n", ush_pos_1, ul_pos_1, uch_pos_1);
    ft_printf("1 => [%hu%lu%hhx]\n", ush_pos_1, ul_pos_1, uch_pos_1);

    printf("1 => [%#037lx]\n", 22337203685477ul);
    ft_printf("1 => [%#037lx]\n", 22337203685477ul);
}

int		main(void)
{
    // printf("################ [ TEST START, up is Real Printf , down is My Printf ] ################\n");
    // di_test();
    // u_test();
    // x_test();
    // c_test();
    // s_test();
    // p_test();
    // n_test();
    // float_bit_test();
   // double a = 1.23456789;
   //  double_bit_test(a);
   //  double_bit_test2(a);
    // test_one_bit_oper();
    // x_bit_test();

//    f_test();
    //double a = -123.45;
    //double b = 0.6789;
    //printf("### 5 ###\n");
    //printf("%% f=>[% f]\n", b);
    //ft_printf("%% f=>[% f]\n", b);

   // big_number_test();

    //double a = 10.123;
    //double_bit_test(a);
    //double_bit_test2(a);
    //printf("###################### Line ####################\n");
    //ft_printf("%%f => [%f]\n", a);
    //ft_printf("%%f => [%f]\n", 11.4567);
    //ft_printf("%%f => [%f]\n", 1351781928.4567);
    //ft_printf("%%f => [%f]\n", 1351781926.4567);
    //ft_printf("%%f => [%f]\n", (double)LLONG_MAX);


    // round_test();
    // printf("#########2####### \n");
    // round_test2();
    // expo_test();


    //double_bit_test(d);
    //double_bit_test2(d);

    // p_test();
    // printf("1 => [%f]\n", -0.0);
    // ft_printf("2 => [%f]\n", -0.0);
    // printf("1 => [%f]\n", -958.125);
    // ft_printf("1 => [%f]\n", -958.125);

    // printf("1 => [%.1f]\n", -3.85);
    // ft_printf("1 => [%.1f]\n", -3.85);
    // double_bit_test(-3.85);

    // printf("1 => [%.1f]\n", 3.85);
    // ft_printf("1 => [%.1f]\n", 3.85);
    // round_test();
    // round_test2();

    // printf("1 => [%#.0f]\n", 0.0);
    // ft_printf("2 => [%#.0f]\n", 0.0);

    // printf("1 => [%#.0f]\n", -7.4);
    // ft_printf("2 => [%#.0f]\n", -7.4);

    // printf("1 => [%05.0f]\n", 0.0);
    // ft_printf("2 => [%05.0f]\n", 0.0);

    // printf("1 => [%05.0f]\n", -0.0);
    // ft_printf("2 => [%05.0f]\n", -0.0);

    // printf("1 => [%05.1f]\n", 0.0);
    // ft_printf("2 => [%05.1f]\n", 0.0);

    // printf("1 => [%010f]\n", 2.1);
    // ft_printf("2 => [%010f]\n", 2.1);

    // printf("1 => [%-05%]\n");
    // ft_printf("2 => [%-05%]\n");

    // printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
    // ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);

    // printf("1 => [%.0f]\n", -4.5);
    // ft_printf("1 => [%.0f]\n", -4.5);

    // printf("%.0f\n", -2.5);
    // ft_printf("%.0f\n", -2.5);

    // printf("%.0f\n", -0.5);
    // ft_printf("%.0f\n", -0.5);

    // printf("%.0f\n", -9.999);
    // ft_printf("%.0f\n", -9.999);

    // printf("%.*f\n", -3, 3.1415926535);
    // ft_printf("%.*f\n", -3, 3.1415926535);

    printf("%.1f\n", -9.999);
    ft_printf("%.1f\n", -9.999);

	return (0);
}


