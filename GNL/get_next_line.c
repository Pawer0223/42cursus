/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:47:44 by taesan            #+#    #+#             */
/*   Updated: 2021/01/03 21:59:32 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char     *append_content(char *buf, char *content)
{
    char *new_content;
    int i;
    int j;

    if (!content)
    {
        if (!(new_content = ft_strdup(buf)))
            return (0);
    }
    else
    {
        if (!(new_content = (char *)malloc(ft_strlen(buf) + ft_strlen(content) + 1)))
            return (0);
        i = 0;
        while (content[i])
        {
            new_content[i] = content[i];
            i++;
        }
        j = 0;
        while (buf[j])
        {
            new_content[i + j] = buf[j];
            j++;
        }
        new_content[i + j] = 0; 
    }
    free(content);
    free(buf);
    return (new_content);
}

char     *create_new(char *content, int idx)
{
    int     i;
    int     len;
    char    *new_content;

    len = ft_strlen(content) - idx + 2;
    if (!(new_content = (char *)malloc(sizeof(char) * len)))
        return (0);
    i = 0;
    while (i < len - 1)
        new_content[i++] = content[idx++];
    new_content[len - 1] = 0;
    return (new_content);
}

int     line_check(int fd, char **contents, char **line, int is_finish)
{
    int     i;
    char    *new_content;
    char    *result;
    
    i = 0;
    while (contents[fd][i])
    {
        if (contents[fd][i] == '\n')
        {
            i++;
            if (!(result = ft_substr(contents[fd], 0, i)))
                return (-1);
            if (!(new_content = create_new(contents[fd], i)))
                return (-1);
            free(contents[fd]);
            contents[fd] = new_content;
            *line = result;
            return (1);
        }
        i++;
    }
    if (is_finish && !(*line = ft_strdup(contents[fd])))
        return (-1);
    return (0);
}

int     finish(int fd, char **contents, char **line, int read_r)
{
    if (read_r == -1)
        return (-1);
    if (contents[fd] && line_check(fd, contents, line, 1) == -1)
        return (-1);
    if (contents[fd])
    {
        free(contents[fd]);
        contents[fd] = 0;
        return (0);
    }
    *line = ft_strdup("");
    return (0);
}

int     get_next_line(int fd, char **line)
{
    static char *contents[FOPEN_MAX];
    char        *buf;
    int         read_r;
    int         line_exist;

    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
        return (-1);
    if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
    while ((read_r = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_r] = 0;
        if (!(contents[fd] = append_content(buf, contents[fd])))
            return (-1);
        line_exist = line_check(fd, contents, line, 0);
        if (line_exist != 0)
            return (line_exist);
    }
    return finish(fd, contents, line, read_r);
}