/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:13:20 by taekang           #+#    #+#             */
/*   Updated: 2020/10/16 18:58:38 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

void	ft_two_print(char **result)
{
	int i = 0;
	while (result[i])
	{
		printf("result[%d] : [%s]\n", i, result[i]);
		i++;
	}
}

void	ft_print(int n)
{
	char c;

	if (n >= 10)
		ft_print(n / 10);

	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_strlen_test(int argc, const char *argv[])
{
	printf("############# ft_strlen_test ###################\n");
	for (int i = 2; i < argc; i++) {
		

		size_t self = ft_strlen(argv[i]);
		size_t lib = strlen(argv[i]);

		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("[ %s ] self =>  %zu , lib => %zu, success : %s\n", argv[i], self, lib, result);
	}
}

void	ft_strlcat_test(int argc, const char *argv[])
{
	int len = 100 * sizeof(char);
	char *dest = (char *)malloc(len);
	char *dest2 = (char *)malloc(len);

	printf("############# ft_strlcat_test ###################\n");
	for (int i = 2; i < argc; i++) {

		memset(dest, 'x', 5);
		memset(dest2, 'x', 5);
		
		printf("Before : [ %s ]\n", dest);
		size_t self = ft_strlcat(dest, argv[i], 20);
		size_t lib = strlcat(dest2, argv[i], 20);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("src : [ %s ], After : [ %s ],  self =>  %zu , lib => %zu, success : %s\n", argv[i], dest, self, lib, result);


		memset(dest, 0, len);
		memset(dest2, 0, len);
	}

	free(dest);
	free(dest2);
}

void	ft_strlcpy_test(int argc, const char *argv[])
{
	int len = 100 * sizeof(char);
	char *dest = (char *)malloc(len);
	char *dest2 = (char *)malloc(len);

	printf("############# ft_strlcpy_test ###################\n");
	for (int i = 2; i < argc; i++) {
	
		size_t size = 5;
		size_t self = ft_strlcpy(dest, argv[i], size);
		size_t lib = strlcpy(dest2, argv[i], size);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("src : [ %s ], result : [ %s ], size : [ %zu ],  self =>  %zu , lib => %zu, success : %s\n", argv[i], dest2, size, self, lib, result);

	}

	free(dest);
	free(dest2);
}

void	ft_strchr_test(int argc, const char *argv[])
{

	printf("############# ft_strchr_test ###################\n");
	for (int i = 2; i < argc; i++) {
	
		char *self = ft_strchr(argv[i], 'a');
		char *lib = strchr(argv[i], 'a');
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("word : [ %s ], self =>  %s , lib => %s, success : %s\n", argv[i], self, lib, result);

	}
}

void	ft_strnstr_test(int argc, const char *argv[])
{
	printf("############# ft_stnstr_test ###################\n");

	if (argc < 3)
		printf("strnstr please call .. => [ strnstr haystack needle ]");

		char *self = ft_strnstr(argv[2], argv[3], 5);
		char *lib = strnstr(argv[2], argv[3], 5);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("haystack : [ %s ], needle : [ %s ],  self =>  %s , lib => %s, success : %s\n", argv[2], argv[3],  self, lib, result);

}

void	ft_strncmp_test(int argc, const char *argv[])
{
	printf("############# ft_stncmp_test ###################\n");

	if (argc < 3)
		printf("strncmp please call .. => [ strnstr haystack needle ]");

		int self = ft_strncmp(argv[2], argv[3], 5);
		int lib = strncmp(argv[2], argv[3], 5);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("s1 : [ %s ], s2 : [ %s ],  self =>  %d , lib => %d, success : %s\n", argv[2], argv[3],  self, lib, result);

}

void	ft_atoi_test(int argc, const char *argv[])
{
	printf("############# ft_atoi_test ###################\n");


	for (int i = 2; i < argc; i++) {
	
		int	self = ft_atoi(argv[i]);
		int lib = atoi(argv[i]);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("word : [ %s ], self =>  %d , lib => %d, success : %s\n", argv[i], self, lib, result);

	}
}

void	ft_substr_test(int argc, const char *argv[])
{
	if (argc < 4) {
		printf("ft_substr please call => ./a.out [src start len]\n");
		return ;
	}
	
	printf("############# ft_substr_test ###################\n");
	
		unsigned int start = atoi(argv[3]);
		size_t len = atoi(argv[4]);
	//	size_t len = 5;	
		char *result = ft_substr(argv[2], start, len);
		printf("ft_substr(%s, %d, %zu) : %s\n", argv[1], start, len, result);
}

void	ft_strjoin_test(int argc, const char *argv[])
{
	if(argc < 4) { 
		printf("ft_strjoin pleas call => ./a.out [s1 s2]\n");
		return ;
	}
	printf("############# ft_strjoin_test ###################\n");

	char *result = ft_strjoin(argv[2], argv[3]);
	printf("s1 : [ %s ], s2 : [ %s ], result : [ %s ]\n", argv[2] , argv[3], result);
}

void	ft_strtrim_test(int argc, const char *argv[])
{
	if(argc < 4) { 
		printf("ft_strtrim pleas call => ./a.out [s1 set]\n");
		return ;
	}
	printf("############# ft_strtrim_test ###################\n");

	char *result = ft_strtrim(argv[2], argv[3]);
	printf("s1 : [ %s ], set : [ %s ], result : [ %s ]\n", argv[2] , argv[3], result);
}

void	ft_split_test(int argc, const char *argv[])
{
	if(argc < 4) { 
		printf("ft_split pleas call => ./a.out [str c]\n");
		return ;
	}

	
	char c;
	char **result;

	c = *argv[3];
	result = ft_split(argv[2], c);

	printf("############# ft_split_test ###################\n");
	printf("##### s1 : [%s], c : [%c] #####\n", argv[2] , c);

	ft_two_print(result);
}

void	ft_itoa_test(const char *argv[])
{
	int n;

	n = ft_atoi(argv[2]);
	char *result = ft_itoa(n);

	printf("############# ft_itoa_test ###################\n");
	printf("##### n(ft_atoi apply..) : [%d], itoa Result : [%s] #####\n", n, result);
}

void	ft_putchar_test(const char *argv[])
{
	char c = argv[2][0];
	int fd = atoi(&argv[3][0]);

	printf("############# ft_putchar_test ###################\n");
	ft_putchar_fd(c, fd);
}

void	ft_putstr_test(const char *argv[])
{
	int fd = atoi(&argv[3][0]);

	printf("############# ft_putstr_test ###################\n");
	ft_putstr_fd((char *)argv[2], fd);
}

void	ft_putendl_test(const char *argv[])
{
	int fd = atoi(&argv[3][0]);

	printf("############# ft_put with end line _test ###################\n");
	ft_putendl_fd((char *)argv[2], fd);
}

void	ft_putnbr_test(const char *argv[])
{
	int  n = atoi(&argv[2][0]);
	int fd = atoi(&argv[3][0]);

	printf("############# ft_putnbr_test ###################\n");
	ft_putnbr_fd(n, fd);
}

char	test_func(unsigned int n, char c)
{
	n++;
	return c + 1;
}

void	ft_strmapi_test(const char *argv[])
{
	char *s = (char *)argv[2];
	char *result = ft_strmapi(s, test_func);

	printf("############# ft_strmapi_test ###################\n");
	printf("origin : [%s], result : [%s]\n", s, result);
}

void	ft_lstnew_test(int argc, const char *argv[])
{
	if (argc < 3)
		printf("ft_lstnew plaese call... ==> lstnew [str]\n");
	char *str = (char *)argv[2];

	t_list *t = ft_lstnew(str);

	printf("############# ft_lstnew_test ###################\n");
	printf("t->content : [%s]\n", (char *)t->content);
}

void	print_list(t_list **lst)
{
	int i = 0;

	t_list *t = lst[0];
	
	while (t)
	{
		printf("lst[%d]->content:[%s]\n",i,t->content);
		t = t->next;
		i++;
	}
}

void	ft_add_front_test(int argc, const char *argv[])
{
	if (argc < 3)
		printf("ft_lstadd_front plaese call... ==> ft_lstadd_front [new]\n");

	t_list *new = ft_lstnew((char *)argv[2]);

	t_list **lst = (t_list **)malloc(sizeof(t_list));
	t_list *t1 = ft_lstnew("first");
	t_list *t2 = ft_lstnew("second");
	t1->next = t2;
	lst[0] = t1;

	printf("### ft_lstadd_front Before..###\n");
	print_list(lst);

	ft_lstadd_front(lst, new);
	printf("### ft_lstadd_front After..###\n");
	print_list(lst);
}

int		main(int argc, const char *argv[])
{

	if (argc <= 2) {
		printf("please input [func_name, arguments]");
	}
	else if (argc > 2) {

		const char *call = argv[1];

		if (strcmp(call, "strlen") == 0)
		{
			ft_strlen_test(argc, argv);
		}
		else if (strcmp(call, "strlcat") == 0)
		{
			ft_strlcat_test(argc, argv);			
		}
		else if (strcmp(call, "strlcpy") == 0)
		{
			ft_strlcpy_test(argc, argv);
		}
		else if (strcmp(call, "strchr") == 0)
		{
			ft_strchr_test(argc, argv);
		}
		else if (strcmp(call, "strnstr") == 0)
		{
			ft_strnstr_test(argc, argv);
		}
		else if (strcmp(call, "strncmp") == 0)
		{
			ft_strncmp_test(argc, argv);
		}
		else if (strcmp(call, "atoi") == 0)
		{
			ft_atoi_test(argc, argv);
		}
		else if (strcmp(call, "substr") == 0)
		{
			ft_substr_test(argc, argv);
		}
		else if (strcmp(call, "strjoin") == 0)
		{
			ft_strjoin_test(argc, argv);
		}
		else if (strcmp(call, "strtrim") == 0)
		{
			ft_strtrim_test(argc, argv);
		}
		else if (strcmp(call, "split") == 0)
		{
			ft_split_test(argc, argv);
		}
		else if (strcmp(call, "itoa") == 0)
		{
			ft_itoa_test(argv);
		}
		else if (strcmp(call, "putchar") == 0)
		{
			ft_putchar_test(argv);
		}
		else if (strcmp(call, "putstr") == 0)
		{
			ft_putstr_test(argv);
		}
		else if (strcmp(call, "putendl") == 0)
		{
			ft_putendl_test(argv);
		}
		else if (strcmp(call, "putnbr") == 0)
		{
			ft_putnbr_test(argv);
		}
		else if (strcmp(call, "strmapi") == 0)
		{
			ft_strmapi_test(argv);
		}
		else if (strcmp(call, "lstnew") == 0)
		{
			ft_lstnew_test(argc, argv);
		}
		else if (strcmp(call, "lstadd_front") == 0)
		{
			ft_add_front_test(argc, argv);
		}
		else {
			printf("Please Call Func..Or Check Func Name !! \n");
		}
	}
	
}
