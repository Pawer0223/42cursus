#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

int	func_check(const char *name)
{
    if (strcmp(name, "strlen") == 0)
	return (1);
    else if (strcmp(name, "strcpy") == 0)
	return (2);
    else if (strcmp(name, "strcmp") == 0)
	return (3);
    else if (strcmp(name, "write") == 0)
	return (4);
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
	else if (seq == 3)
	{
	    if (argc < 4)
		printf("a.out strcmp $1, $2\n");
	    else {
		int result = ft_strcmp(argv[2], argv[3]);
		printf("ft_strcmp(%s, %s) => [%d]\n", argv[2], argv[3], result);
	    }
	}
	else if (seq == 4)
	{
	    char wn = '\n';
	    ft_write(1, argv[2], ft_strlen(argv[2]));
	    ft_write(1, &wn, 1);
	}
    }
}
