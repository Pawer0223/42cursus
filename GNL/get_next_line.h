#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
    struct s_list   *prev;
}               t_list;

int             get_next_line(int fd, char **line);
t_list	        *ft_lstnew(void *content , t_list *curr);
void            ft_lstdelone(t_list *list);
void	        ft_lstclear(t_list *list);
t_list          *append_list(char *buf, t_list *list);

/**
 ** remove
**/
# include <stdio.h>
# include <fcntl.h>

#endif