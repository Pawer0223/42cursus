/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:26:34 by taesan            #+#    #+#             */
/*   Updated: 2021/02/21 17:20:05 by taekang          ###   ########.fr       */
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
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
// int		ft_strlen(char *s);
// char	*ft_strdup(char *s1);
// size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
// char	*ft_substr(char *s, int start, size_t len);
char	*content_null(char *buf);

#endif
