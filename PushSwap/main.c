#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // remove !

#include "libft/libft.h"
#include "list/list.h"
#include "error.h"

/*
	** 1개일때도 잘 free되는지
*/ 
void	one_list_test()
{
	t_list	*start;
	int		size;

	start = 0;
	size = ft_lstsize(&start);
	start = ft_lstnew(&start, ft_strdup("[ ### Just One Element ### ]"));
	ft_list_print(&start);
	printf("list size : %d\n", size); // remove !
	ft_lstclear(&start);
}

void	list_test()
{
	t_list	*start;
	int		size;

	start = 0;
	size = ft_lstsize(&start);
	start = ft_lstnew(&start, ft_strdup("[ ### start ### ]"));
	printf("list size : %d\n", size); // remove !
	ft_lstadd_front(&start, ft_lstnew(&start, ft_strdup("front add 1")));
	ft_lstadd_front(&start, ft_lstnew(&start, ft_strdup("front add 2")));
	ft_lstadd_front(&start, ft_lstnew(&start, ft_strdup("front add 3")));
	ft_lstadd_back(&start, ft_lstnew(&start,  ft_strdup("back add 1")));
	ft_lstadd_back(&start, ft_lstnew(&start,  ft_strdup("back add 2")));
	ft_lstadd_back(&start, ft_lstnew(&start,  ft_strdup("back add 3")));
	ft_list_print(&start);
	size = ft_lstsize(&start);
	printf("list size : %d\n", size); // remove !
	ft_lstclear(&start);

}

int		main(void)
{
	list_test();
	// one_list_test();
	while(1); // remove, for leak test
}