#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int     get_next_line(int fd, char **line);
int     ft_strlen(char *s);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);
/**
 ** remove
**/
# include <stdio.h>
# include <fcntl.h>

#endif