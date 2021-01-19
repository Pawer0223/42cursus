/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:40:00 by taekang           #+#    #+#             */
/*   Updated: 2021/01/19 02:56:50 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// remove
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*str_append(char *contents, char *buf)
{
	int 	i;
	int 	j;
	int 	b_len;
	int		c_len;
	char	*new_con;

	b_len = ft_strlen(buf);
	c_len = ft_strlen(contents);
	new_con = (char *)malloc(sizeof(char) * (b_len + c_len + 1));
	if (!new_con)
		return (0);
	i = 0;
	while (contents && contents[i])
	{
		new_con[i] = contents[i];
		i++;
	}
	j = 0;
	while (buf && buf[j])
	{
		new_con[i + j] = buf[j];
		j++;
	}
	new_con[i + j] = 0;
	if (contents)
		free(contents);
	return (new_con);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;
	int		len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_substr(char *str, int start, int len)
{
	int		s_len;
	int		i;
	char	*result;

	s_len = ft_strlen(str);
	if (start >= s_len)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[start] && i < len)
		result[i++] = str[start++];
	result[i] = 0;
	return (result);	
}

int		line_exist(char **contents, char **line)
{
	char	*con;
	char	*new_con;
	int		i;
	int		len;

	con = *contents;
	i = 0;
	while (con[i])
	{
		if (con[i] == '\n')
		{
			*line = ft_substr(*contents, 0, i);
			if (!*line)
				return (-1);
			len = ft_strlen(con);
			new_con = ft_substr(con, i + 1, (len - i + 1));
			if (!new_con)
			{
				free(*line);
				return (-1);
			}
			free(con);
			*contents = new_con;
			return (1);
		}
		i++;
	}
	return (0);
}

int		finish(int rd_r, char *contents, char **line)
{
	int exist;

	if (rd_r < 0)
		return (-1);
	exist = (!contents) ? 0 : line_exist(&contents, line);
	if (exist)
		return (exist);
	if (contents)
	{
		*line = ft_strdup(contents);
		free(contents);
		contents = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	char		buf[BUFFER_SIZE];
	static char	*contents;
	int			rd_r;
	int			exist;

	while (((rd_r = read(0, buf, BUFFER_SIZE)) > 0))
	{
		buf[rd_r] = 0;
		contents = str_append(contents, buf);
		if (!contents)
			return (0);
		exist = line_exist(&contents, line);
		if (exist != 0)
			return (exist);
	}
	return (finish(rd_r, contents, line));
}

// int		main(void)
// {
// 	int		r;
// 	char	*line;
// 
// 	line = NULL;
// 	while ((r = get_next_line(&line)) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("%s", line);
// 	free(line);
// 	line = NULL;
// }
