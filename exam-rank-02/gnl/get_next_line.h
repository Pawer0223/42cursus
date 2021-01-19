/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:13 by taekang           #+#    #+#             */
/*   Updated: 2021/01/18 21:59:23 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H 

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 1024 
#endif

#ifndef OPEN_MAX
 #define OPEM_MAX 1000
#endif

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int		get_next_line(char **line);

#endif

