/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:44:55 by taekang           #+#    #+#             */
/*   Updated: 2020/10/14 17:11:37 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print(char **result)
{
	int i = 0;
	while (result[i])
	{
		printf("result[%d] : %s\n", i, result[i]);
		i++;
	}
}

size_t		get_cnt(char const *s, char c)
{
	int i;
	size_t cnt;
	size_t len;

	len = ft_strlen(s);
	i = 0;
	cnt = 2;
	while(s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	if (len == cnt - 2)
		return (1);
	return (cnt);
}

void	mem_free(char **result, int seq)
{
	while (seq - 1 >= 0)
	{
		free(result[seq - 1]);
		seq--;
	}
	free(result);
}

char	*add_str(char **result, int seq, char *src, size_t n)
{
	char *dst;

	if (!(dst = (char *)malloc(sizeof(char) * n)))
	{
		mem_free(result, seq);
		return (0);
	}
	ft_strlcpy(dst, src, n);
	result[seq] = dst;
	return (dst);
}

int		set_result(char **result, char const *s, char c)
{
	int		start;
	int		end;
	int		seq;
	char	*src;

	seq = 0;
	start = 0;
	end = 0;
	src = (char *)s;
	while (src[end])
	{
		if (src[end] == c)
		{
			if (end - start > 0)
			{
				if (!add_str(result, seq, src + start, (end - start + 1)))
					return (0);
				seq++;
			}
			start = end + 1;
		}
		end++;
	}
	if (end - start > 0)
	{
		if(!add_str(result, seq, src + start, (end - start + 1)))
			return (0);
	}
	return (seq + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cnt;
	int		i;
	int		seq;

	seq = 0;
	cnt = get_cnt(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * cnt)))
		return (0);
	if (cnt != 1)
	{
		if (!(seq = set_result(result, s, c)))
			return (0);
	}
	result[seq] = 0;
	return (result);
}


void	call(int argc, char *argv[])
{
	char c;
	char **result;

	c = *argv[2];
	result = ft_split(argv[1], c);
	ft_print(result);
}

int		main(int argc, char *argv[])
{
	call(argc, argv);
	return (0);
}
