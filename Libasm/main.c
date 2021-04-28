#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);

int	func_check(const char *name)
{
    if (strcmp(name, "strlen") == 0)
	return (1);
    else if (strcmp(name, "strcpy") == 0)
	return (2);
    return (0);
}

int	main(int argc, const char *argv[])
{
    if (argc < 3)
	printf("please input parameter\n");
    else
    {
	int seq = func_check(argv[1]);

	if (seq == 1)
	{
	    int len = ft_strlen(argv[2]);
	    printf("[%s] : %d\n", argv[2], len);
	}
	else if (seq == 2)
	{
	    int len = ft_strlen(argv[2]);
	    char *dest = (char *)malloc(len);
	    ft_strcpy(dest, argv[2]);
	    printf("dest => [%s]\n", dest);
	    free(dest);
	}
    }
}
