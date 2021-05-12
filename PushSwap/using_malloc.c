/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:24 by taesan            #+#    #+#             */
/*   Updated: 2021/05/12 18:54:11 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*make_num(long long num)
{
	int	*ptr;

	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (!(ptr = (int *)malloc(sizeof(int))))
		return (0);
	*ptr = (int)num;
	return (ptr);
}

int		make_list(t_list **list, int argc, const char *argv[])
{
	int		i;
	int		*num;
	t_list	*data;

	i = 1;
	*list = 0;
	while (i < argc)
	{
		if (!(num = check_param(argv[i])))
			return (error_occur(list));
		if (!(data = ft_lstnew(num)))
		{
			free(num);
			return (error_occur(list));
		}
		if (i == 1)
			*list = data;
		else
			ft_lstadd_back(list, data);
		i++;
	}
	return (1);
}
