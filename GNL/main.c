/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/01/02 16:28:03 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int     main(void)
{
    char **line;

    int fd = open("./test.txt", O_RDONLY);

    line = (char **)malloc(sizeof(char *) * 10);
    
    int i = 1;
    while (get_next_line(fd, line)) {
        printf("[%d] : [%s]\n", i++, *line);
    }

    return (0);
}