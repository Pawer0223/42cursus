/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:47:44 by taesan            #+#    #+#             */
/*   Updated: 2021/01/01 18:53:43 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(int fd, char **line)
{
    char        *buf;
    static char *temp;
    int         read_result;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    whlie(read_result = read(fd, buf, BUFFER_SIZE) > 0)
    {
        
    }
    if (read_result < 0)
        return (-1);
    read(fd, buf, BUFFER_SIZE);
    printf("get_next_line !!!!! \n");

    printf("buffer size : [%d]\n", BUFFER_SIZE);
    
    return (0);
}