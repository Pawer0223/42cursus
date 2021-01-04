/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:26:34 by taesan            #+#    #+#             */
/*   Updated: 2021/01/04 14:29:12 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*content_null(char *buf, char *content);

#endif
