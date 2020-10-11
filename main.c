/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:13:20 by taekang           #+#    #+#             */
/*   Updated: 2020/10/11 14:43:57 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

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

	char *result = ft_strjoin(argv[2], argv[3]);
	printf("s1 : [ %s ], s2 : [ %s ], result : [ %s ]\n", argv[2] , argv[3], result);
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
		else if (strcmp(call, "all") == 0)
		{
			ft_strlen_test(argc, argv);
			ft_strlcat_test(argc, argv);			
			ft_strlcpy_test(argc, argv);
			ft_strchr_test(argc, argv);
			ft_strnstr_test(argc, argv);
			ft_strncmp_test(argc, argv);
			ft_atoi_test(argc, argv);
		}
		else {
			printf("Please Call Func..Or Check Func Name !! \n");
		}
	}
	
}
