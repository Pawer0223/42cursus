/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:10:08 by taekang           #+#    #+#             */
/*   Updated: 2021/01/18 22:35:40 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	if (!str)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
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

char		*str_append(char *contents, char *buf)
{
	int		con_len;
	int		buf_len;
	char	*new_con;
	int		i;
	int		j;

	con_len = ft_strlen(contents);
	buf_len = ft_strlen(buf);
	if (!(new_con = (char *)malloc(sizeof(char) * (con_len + buf_len + 1))))
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

char		*ft_substr(char *str, int idx, int len)
{
	int		i;
	char	*result;

	if (!str)
		return (0);
	if (idx >= ft_strlen(str))
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (str[idx] && i < len)
		result[i++] = str[idx++];
	result[i] = 0;
	return (result);
}

int		line_exist(char **contents, char **line)
{
	int		i;
	int		con_len;
	char	*new_con;
	char	*con;

	con = *contents;
	i = 0;
	while (con[i])
	{
		if (con[i] == '\n')
		{
			*line = ft_substr(con, 0, i);
			if (!*line)
				return (-1);
			con_len = ft_strlen(con);
			new_con = ft_substr(con, i + 1, (con_len - i + 1));
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

int		finish(int rd_r, char **con, char **line)
{
	int exist;

	if (rd_r < 0)
		return (-1);
	exist = (*con == 0) ? 0 : line_exist(con, line);
	if (exist)
		return (exist);
	*line = 0;
	if (*con)
	{
		*line = ft_strdup(*con);
		free(*con);
		con = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	int			rd_r;
	int			exist;
	static char	*contents;
	char		buf[BUFFER_SIZE + 1];

	while (((rd_r = read(0, buf, BUFFER_SIZE)) > 0))
	{
		buf[rd_r] = 0;
		if (!(contents = str_append(contents, buf)))
			return (0);
		exist = line_exist(&contents, line);
		if (exist != 0)
			return (exist);
	}
	return (finish(rd_r, &contents, line));
}
   //  int main(void)
   //  {
   //  	int		r;
   //  	char	*line;
   //  
   //  	line = NULL;
   //  	while ((r = get_next_line(&line)) > 0)
   //  	{
   //  		printf("%s\n", line);
   //  		free(line);
   //  		line = NULL;
   //  	}
   //  	printf("%s", line);
   //  	free(line);
   //  	line = NULL;
   //  }
