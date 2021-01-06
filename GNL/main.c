/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/01/06 14:05:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

#include "get_next_line.h"
int     main(void)
{
    char *str = 0;
    int fd = open("./test.txt", O_RDONLY);
    int result = get_next_line(fd, &str);

    int i = 1;
    while (result != 0) {
        printf("[%d] => [%s] , ", i++, str);
        result = get_next_line(fd, &str);
    }
    printf("Last => [%d] => [%s]", i, str);
    if (str)
        free(str);
//     char **line;

//     int fd = open("./test.txt", O_RDONLY);
//     line = (char **)malloc(sizeof(char *) * 10);
//     int i = 1;
//     printf("### is My ###\n");
//     int result = get_next_line(fd, line);

//     if (result == 0)
//         printf("[%d] => %s\n", i++, *line);
//     while (result != -1 && result) {
//         printf("[%d] => %s\n", i++, *line);
//         result = get_next_line(fd, line);
//         if (!result)
//             printf("[%d] => %s\n", i++, *line);
//     }
//     if (*line)
//         free(*line);
//     free(line);
    
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