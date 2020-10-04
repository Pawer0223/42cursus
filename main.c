/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:24:15 by taekang           #+#    #+#             */
/*   Updated: 2020/10/05 04:42:00 by taekang          ###   ########.fr       */
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
	
		size_t self = ft_strlcpy(dest, argv[i], 5);
		size_t lib = strlcpy(dest2, argv[i], 5);
		char *result = "true";

		if (self != lib)
			result = "fail";

		printf("src : [ %s ], result : [ %s ],  self =>  %zu , lib => %zu, success : %s\n", argv[i], dest, self, lib, result);

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
		else if (strcmp(call, "all") == 0)
		{
			ft_strlen_test(argc, argv);
			ft_strlcat_test(argc, argv);			
			ft_strlcpy_test(argc, argv);
			ft_strchr_test(argc, argv);
		}
		else {
			printf("please call func\n");
		}
	}
	
}
