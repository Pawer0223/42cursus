#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // remove !

#include "libft/libft.h"
#include "list/list.h"
#include "error.h"

void	list_test()
{
	t_list	*start;
	int		size;

	start = 0;
	size = ft_lstsize(&start);
	start = ft_lstnew(&start, "start");
	printf("size : %d\n", size); // remove !

	ft_lstadd_front(&start, ft_lstnew(&start, "front add 1"));
	ft_lstadd_front(&start, ft_lstnew(&start, "front add 2"));
	ft_lstadd_front(&start, ft_lstnew(&start, "front add 3"));
	ft_lstadd_back(&start, ft_lstnew(&start, "back add 1"));
	ft_lstadd_back(&start, ft_lstnew(&start, "back add 2"));
	ft_lstadd_back(&start, ft_lstnew(&start, "back add 3"));
	ft_list_print(&start);
	
	size = ft_lstsize(&start);
	printf("size : %d\n", size); // remove !
	ft_lstclear(&start);

	while (1);
}

int		main(void)
{
	list_test();
}