/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:19:05 by taesan            #+#    #+#             */
/*   Updated: 2021/03/14 04:32:08 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_occur(const char *error_message)
{
	printf("Error\n");
	printf(": [%s]\n", error_message);
	return (0);
}

char	*content_null(char *buf)
{
	char *new_content;

	if (!(new_content = ft_strdup(buf)))
		return (0);
	return (new_content);
}

int		ft_max(int a, int b)
{
	return (a > b) ? a : b;
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) || line[i] != ' ' || line[i] != ',')
			return (0);
		i++;
	}
	return (1);
}
