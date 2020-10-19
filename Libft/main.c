#include "libft.h"
#include <stdio.h>

int		main()
{
	char src[10] ="12345";
//	void *dst = (void *)malloc(0);
	const void *dst = (void *)malloc(0);
	// ft_memcpy(dst, "123", 3);
	ft_memcpy(src, dst, 3);

	printf("dst : %s\n", (char *)dst);


	return (0);
}
