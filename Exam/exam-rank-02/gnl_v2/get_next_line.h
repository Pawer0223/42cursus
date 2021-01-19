/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:38:21 by taekang           #+#    #+#             */
/*   Updated: 2021/01/19 01:41:04 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 1024
#endif

#ifndef OPEN_MAX
 #define OPEN_MAX 1024
#endif

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(char **line);

#endif
