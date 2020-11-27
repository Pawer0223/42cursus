#include "printf.h"
#include <limits.h>

int		main(void)
{
	// ft_printf("num1[%10ld], str is [%lls], char is [%hc], float is [%hhf]", 1, "str", 'a', 0.123);
	// ft_printf("test");
	printf("long long int size is %d\n", sizeof(long long int));
	
	
	// ft_printf("num check 1 => [%lld] , 2 => [% d] , 3 => [%+lld]", 123, +6403, 456); // possible
	ft_printf("num check 1 => [%lld] , 2 => [% d] , 3 => [%+lld]", LLONG_MIN, +6403, LLONG_MAX);
}
