#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);

int	main(int argc, const char *argv[])
{
    if (argc < 2)
	printf("please input parameter\n");
    else
    {
	for (int i = 1; i < argc; i++) {
	    int len = ft_strlen(argv[i]);
	    printf("[%s] : %d\n", argv[i], len);
	}
    }
}
