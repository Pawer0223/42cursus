/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:00:15 by taesan            #+#    #+#             */
/*   Updated: 2021/04/18 16:04:25 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef LIBASM_H
# define LIBASM_H

size_t	    ft_strlen(const char *str);
char	    *ft_strcpy(char *dest, const char *src);
int	    ft_strcmp(const char *s1, const char *s2);
ssize_t	    ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);
char	    *ft_strdup(const char *s1);

# endif
