#include "printf.h"
#include <limits.h>

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
    printf("### 16 ###\n");
    printf   ("%%i =>[%i]\n", INT_MAX + 100);
    ft_printf("%%i =>[%i]\n", INT_MAX + 100);
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
}

int		main(void)
{
    printf("################ [ TEST START, up is Real Printf , down is My Printf ] ################\n");
    // di_test();
    // u_test();
    // x_test();
    // c_test();
    s_test();
	return (0);

}
