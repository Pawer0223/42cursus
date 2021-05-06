#include "push_swap.h"

/*
	** 1개일때도 잘 free되는지
*/ 
void	one_list_test()
{
	t_list	*start;
	int		size;

	start = 0;
	start = ft_lstnew(&start, ft_strdup("[ ### Just One Element ### ]"));
	size = ft_lstsize(&start);
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

/*
	** [+, - ]is only exist zero index !
*/
int		is_number(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' && i == 0)
			i++;
		else if (str[i] == '+' && i == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int		make_list(int argc, const char *argv[], t_list **s)
{
	int		i;
	int		*num;
	t_list	*data;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		if (!(num = (int *)malloc(sizeof(int))))
			return (0);
		*num = ft_atoi(argv[i]);
		if (!(data = ft_lstnew(s, num)))
			return (0);
		if (i == 1)
			*s = data;
		else
			ft_lstadd_back(s, data);
		i++;
	}
	return (1);
}
/*
	** push swap !
*/
int		main(int argc, const char *argv[])
{
	// list_test();
	// one_list_test();
	t_list	*start;
	
 	if (argc < 2) {
		return (error_occur(0));
	}
	else
	{
		start = 0;
		if (!make_list(argc, argv, &start))
			return (error_occur(&start));
		ft_list_print(&start);
		while(1); // remove, for leak test
		return (1);
	}

}