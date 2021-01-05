/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/01/05 16:23:16 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

#include "get_next_line.h"
int     main(void)
{
    char **line;

    int fd = open("./test.txt", O_RDONLY);
    line = (char **)malloc(sizeof(char *) * 10);
    int i = 1;
    printf("### is My ###\n");
    int result = get_next_line(fd, line);

    if (result == 0)
        printf("[%d] => %s", i++, *line);
    while (result) {
        printf("[%d] => %s", i++, *line);
        result = get_next_line(fd, line);
    }
    // FILE *fp = fopen("./test.txt", "r");
    // size_t line_buf_size = 10;    
    // char *line_buf = NULL;
    // result = getline(&line_buf, &line_buf_size, fp);
    // printf("\n### is getline ###\n");
    // i = 1;
    // while (result >= 0) {
    //     printf("[%d] => %s", i++, *&line_buf);
    //     result = getline(&line_buf, &line_buf_size, fp);
    // }

    return (0);
}