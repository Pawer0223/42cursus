/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:26:34 by taesan            #+#    #+#             */
/*   Updated: 2021/01/06 14:03:22 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_substr(char *s, int start, size_t len);
char	*content_null(char *buf);
size_t  ft_strlen(const char *str);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);

#endif
