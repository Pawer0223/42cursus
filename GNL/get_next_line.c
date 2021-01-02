/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:47:44 by taesan            #+#    #+#             */
/*   Updated: 2021/01/02 19:26:22 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     return_error(char *buf, t_list *list)
{
    if (!list)
        ft_lstclear(list);
    free(buf);
    return (-1);
}

char	*gnl_substr(char const *s, size_t len)
{
    int     idx;
	char	*dst;

    idx = 0;
	if (!s)
		return (0);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
    while (s[idx] && idx < len)
    {
        dst[idx] = s[idx];
        idx++;
    }
    dst[idx] = 0;
	return (dst);
}

int     exist_line(char *buf, char **line, t_list *list)
{
    int     i;
    char    *result;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
        {
            if (!(result = gnl_substr(buf, i)))
                return (return_error(buf, list));
            *line = result;
            free(buf);
            return (1);
        }
        i++;
    }
    return (0);
}

int     get_next_line(int fd, char **line)
{
    char            *buf;
    static t_list   *list;
    int             rr;
    int             r;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buf = malloc(BUFFER_SIZE + 1)))
        return (-1);
    while((rr = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[rr] = 0;
        if (!(list = append_list(buf, list)))
            return (return_error(buf, list));
        if (r = exist_line(buf, line, list) == 1)
            return (1);
        if (r == -1)
            return (-1);
    }
    ft_lstclear(list);
    if (rr == -1)
        return (-1);
    return (0);
}