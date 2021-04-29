#include "libasm.h"

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
    else if (strcmp(name, "read") == 0)
	return (5);
    else if (strcmp(name, "strdup") == 0)
	return (6);
    else if (strcmp(name, "bonus1") == 0)
	return (7);
    else if (strcmp(name, "bonus2") == 0)
	return (8);

    printf("[not found func nm]\n");
    return (0);
}

t_list	*ft_create_elem(void *data)
{
    t_list *list = malloc(sizeof(t_list));

    list->data = data;
    list->next = 0;
    return (list);
}

void	print_list(t_list *list, char *spec)
{
    // spec = specifier

    if (!list) {
	printf("list is null\n");
	return ;
    }

    int	    i = 0;
    t_list  *curr = list;
    
    while (1)
    {
	void *data = curr->data;
	if (ft_strcmp(spec, "%s") == 0)
	    printf("list.get(%d) : %s\n", i++, data);
	else if (ft_strcmp(spec, "%d") == 0)
	    printf("list.get(%d) : %d\n", i++, *(int *)data);
	curr = curr->next;
	if (!curr)
	    return ;
    }
}

void	bonus1_test(int argc, const char *argv[])
{
    t_list *start = ft_create_elem("[start]");

    int i = 2;
    while (i < argc)
    {
	ft_list_push_front(&start, (char *)argv[i]);
	i++;
    }
    print_list(start, "%s");
}

void	bonus2_test(const char *argv)
{
    int cnt = atoi(argv);
    t_list *start = ft_create_elem(&cnt);

    for (int i = cnt - 1; i > 0; i--)
    {
	int *n = malloc(sizeof(int));
	n[0] = i;
	ft_list_push_front(&start, n);
    }
    print_list(start, "%d");
    int size = ft_list_size(start);
    printf("size : %d\n", size);
}

int	main(int argc, const char *argv[])
{
	int seq = func_check(argv[1]);

	if (seq == 1)
	{
	    if (argc < 3)
	    {
		printf("a.out strlen [input]\n");
		return (0);
	    }
	    int len = ft_strlen(argv[2]);
	    printf("[%s] : %d\n", argv[2], len);
	}
	else if (seq == 2)
	{
	    if (argc < 3)
	    {
		printf("a.out strcpy [input]\n");
		return (0);
	    }
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
	else if (seq == 5)
	{
	    if (argc < 4) {
		printf("a.out read [file name] [buffer size]\n");
		return (0);
	    }

	    int fd = open(argv[2], O_RDONLY);
	    if (fd < 0)
		printf("file open error\n");
	    else {
		char *str = 0;
		int result = get_next_line(fd, &str);

		int i = 1;
		while (result != 0) {
		    printf("line %d => [%s]\n", i++, str);
		    result = get_next_line(fd, &str);
		}
		printf("line %d => [%s]\n", i++, str);
		if (str)
		    free(str);
	    }
	}
	else if (seq == 6)
	{
	    if (argc < 3)
	    {
		printf("a.out strdup [input]\n");
		return (0);
	    }
	    char *dup = ft_strdup(argv[2]);
	    if (!dup)
		printf("ft_strdup result is 0\n");
	    printf("duplicate => [%s]\n", dup);
	    if (dup)
		free(dup);
	}
	else if (seq == 7)
	{
	    if (argc < 3) {
		printf("a.out bonus1 [str1 str2 ...]\n");
		return (0);
	    } 
	    bonus1_test(argc, argv);
	}
    	else if (seq == 8)
	{
	    if (argc < 3) {
		printf("a.out bonus2 [size(int)]\n");
		return (0);
	    }
	    bonus2_test(argv[2]);
	}
}
