#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "list/list.h"

int		main(void)
{
	t_list *start;
	
	start = 0;
	start = ft_lstnew(&start, "start");
	ft_lstadd_front(&start, ft_lstnew(&start, "add 1"));
	ft_lstadd_front(&start, ft_lstnew(&start, "add 2"));
	ft_lstadd_front(&start, ft_lstnew(&start, "add 3"));


	ft_list_print(&start);
}