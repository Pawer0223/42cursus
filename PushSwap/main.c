/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/12 19:06:20 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, const char *argv[])
{
	t_list	*list;
	if (argc < 2)
		return (error_occur(0));
	else
	{
		if (!make_list(&list, argc, argv))
			return (0);
	}
	ft_lstiter(list, &print_list); // for test
	ft_lstclear(&list, &delete_content); // check need
}
