/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:44:55 by taekang           #+#    #+#             */
/*   Updated: 2020/10/15 00:27:00 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		get_cnt(char const *s, char c)
{
	int		i;
	size_t	cnt;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	cnt = 2;
	while (s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	if (len == cnt - 2)
		return (1);
	return (cnt);
}

int			add_str(char **result, int seq, char *src, size_t n)
{
	char *dst;

	if (n <= 1)
		return (1);
	if (!(dst = (char *)malloc(sizeof(char) * n)))
	{
		while (seq - 1 >= 0)
		{
			free(result[seq - 1]);
			seq--;
		}
		free(result);
		return (0);
	}
	ft_strlcpy(dst, src, n);
	result[seq] = dst;
	return (1);
}

int			set_result(char **result, char const *s, char c, int seq)
{
	int		l;
	int		r;

	l = 0;
	r = 0;
	while (s[r])
	{
		if (s[r] == c)
		{
			if (!add_str(result, seq, (char *)(s + l), (r - l + 1)))
				return (0);
			if (r - l > 0)
				seq++;
			l = r + 1;
		}
		r++;
	}
	if (!add_str(result, seq, (char *)(s + l), (r - l + 1)))
		return (0);
	if (r - l > 0)
		seq++;
	return (seq);
}

char		**ft_split(char const *s, char c)
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
		if (!(seq = set_result(result, s, c, 0)))
			return (0);
	}
	result[seq] = 0;
	return (result);
}
