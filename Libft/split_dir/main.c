/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:13:20 by taekang           #+#    #+#             */
/*   Updated: 2020/10/14 19:09:02 by taekang          ###   ########.fr       */
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

void	ft_split_test(int argc, const char *argv[])
{
	char c;
	char **result;

	c = *argv[2];
	result = ft_split(argv[1], c);

	printf("############# ft_split_test ###################\n");
	printf("##### s1 : [ %s ], c : [ %c ] #####\n", argv[1] , c);

	ft_two_print(result);
}

int		main(int argc, const char *argv[])
{
	ft_split_test(argc, argv);
}
