#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(int argc, char *argv[])
{
	int r = argc;
	r++;

	char *s = argv[1];
	printf("input : %s\n", s);

	char *dst = (char *)malloc(0);
	size_t dstsize = 3;
	ft_strlcpy(dst, NULL, dstsize);
	printf("dest : [%s]\n", dst);

	return (0);
}
