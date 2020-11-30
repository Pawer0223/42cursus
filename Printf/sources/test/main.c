#include "printf.h"
#include <limits.h>

void	num_test()
{
    ft_printf("%%-.10d :[%-.10d]\n", 12345);
    // printf("%%020.10d :[%020.10d]\n", 12345); // warning
    ft_printf("%%010d :[%010d]\n", 12345);
    // printf("%%010.1d :[%010.1d]\n", 12345); // warning
    ft_printf("%%10d :[%10d]\n", 12345);
    ft_printf("%%010d :[%010d]\n", 12345);
    ft_printf("%%3.10d :[%3.10d]\n", 12345);
    ft_printf("%%10.3d :[%10.3d]\n", 12345);
    ft_printf("%%3.3d :[%3.3d]\n", 12345);
    ft_printf("%%d :[%d]\n", 12345);
    ft_printf("%% d :[% d]\n", 12345);
    ft_printf("%%+d :[%+d]\n", 12345);
    ft_printf("%%+d :[%+d]\n", +123);
    ft_printf("%%+d :[%+d]\n", -123);
    ft_printf("%%10.5d :[%10.5d]\n", 123);
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

    
    num_test();
	return (0);

}
