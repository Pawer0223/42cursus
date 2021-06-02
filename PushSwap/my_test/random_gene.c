/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_gene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:13:50 by taesan            #+#    #+#             */
/*   Updated: 2021/06/02 18:58:49 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1001

int main(int argc, char *argv[])
{
	char visited[MAX];

	for (int i = 0; i < MAX; i++)
		visited[i] = 0;

	if (argc < 2)
	{
		printf("please call ./random [cnt]\n");
	}
	else
	{
		int n = atoi(argv[1]);
		srand(time(NULL)); // 매번 다른 시드값 생성

		int random = 0; // 정수형 변수 선언
		for (int i = 0; i < n; i++)
		{
			while (1) {
				random = rand() % 1000 + 1;	// 난수 생성
				if (!visited[random]) {
					visited[random] = 1;
					break;
				}
			}
			printf("%d", random);
			if (i != n -1)
				printf(" ");
		}
	}
}