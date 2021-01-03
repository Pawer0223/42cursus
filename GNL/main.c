/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/01/03 22:03:08 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int     main(void)
{
    char **line;
    char **line2;

    int fd = open("./test.txt", O_RDONLY);
    int fd2 = open("./test.txt", O_RDONLY);

    line = (char **)malloc(sizeof(char *) * 10);
    line2 = (char **)malloc(sizeof(char *) * 10);
    
    int i = 1;
    printf("### is My ###\n");
    while (1) {
        int result = get_next_line(fd, line);
        printf("[%d] => %s", i++, *line);
        if (!result)
            break;
    }

    return (0);
}