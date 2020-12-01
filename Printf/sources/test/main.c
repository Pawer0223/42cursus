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
}



int		main(void)
{
	// ft_printf("num1[%10ld], str is [%lls], char is [%hc], float is [%hhf]", 1, "str", 'a', 0.123);
	// ft_printf("test");
	
	
	// ft_printf("num check 1 => [%lld] , 2 => [% d] , 3 => [%+lld]", 123, +6403, 456); // possible
	// ft_printf("num check 1 => [%lld] , 2 => [% d] , 3 => [%+lld]", LLONG_MIN, +6403, LLONG_MAX);
	//int zeroI = 0;
	//float zeroF = 0;
	// zeroI : [], zeroF : [0]
	// ft_printf("zeroI : [%.d], zeroF : [%.f]", zeroI, zeroF);
    
    printf("################ [ TEST START, up is Real Printf , down is My Printf ] ################\n");
    di_test();
    u_test();
    x_test();
	return (0);

}
