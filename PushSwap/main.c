#include "push_swap.h"

void	print_list(void *content)
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putchar_fd('\n', 1);
}

int		*make_num(int num)
{
	int	*ptr;

	if (!(ptr = (int *)malloc(sizeof(int))))
		return (0);
	*ptr = num;
	return (ptr);
}

int		check_int_range(int flag, const char *str)
{
	if (!str)
		return (0);
	if (flag == 1 && ft_strcmp(str, MAX) > 0)
		return (0);
	if (flag == -1 && ft_strcmp(str, MIN) > 0)
		return (0);
	return (1);
}

int		*check_param(const char *str)
{
	int			i;
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		flag *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!check_int_range(flag, &str[i]))
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (!str[i])
		return make_num((int)(result * flag));
	return (0);
}

int		main(int argc, const char *argv[])
{
	int		i;
	int		*num;
	t_list	*list;
	t_list	*data;

	if (argc < 2)
		return (error_occur(0));
	else
	{
		list = 0;
		i = 1;
		while (i < argc)
		{
			if (!(num = check_param(argv[i])))
				return (error_occur(&list));
			if (!(data = ft_lstnew(num)))
				return (error_occur(&list));
			if (i == 1)
				list = data;
			else
				ft_lstadd_back(&list, data);
			i++;
		}
		ft_lstiter(list, &print_list); // for test
	}
	ft_lstclear(&list, &delete_content); // check need
}