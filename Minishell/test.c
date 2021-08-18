/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:55:25 by taesan            #+#    #+#             */
/*   Updated: 2021/08/19 03:32:45 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int     main(int argc, char *argv[], char *envp[])
{
	char	**new_envp;
	char	**temp;
	int		idx;

	temp = envp;
	idx = 0;
	while (*temp)
	{
		temp++;
		idx++;
	}
    new_envp = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!new_envp)
		return (0);
	// 이걸먼저 해주고, 에러일 때 밖에서 free해주기.
	// info->envp = new_envp;
	printf("size : [%d]\n", idx);
    new_envp[idx] = 0;
    idx = 0;
    // 다시 말록해서
	while (*envp)
	{
        new_envp[idx] = ft_strdup(*envp);
		if (!new_envp[idx])
			return (0);
		idx++;
		envp++;
	}

	idx = 0;
	while (new_envp[idx])
	{
		printf("new_envp[%d]: [%s]\n", idx, new_envp[idx]);
		idx++;
	}

	return (0);
}
