/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 15:49:08 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, const char *argv[])
{
	t_list		*list;
	t_stacks	*stacks;

	if (argc < 2)
		return (error_occur(0));
	else
	{
		if (!init_list(&list, argc, argv))
			return (0);
		if (!init_stacks(&stacks, list))
			return (0);
		/* 
			** list만드는 것 까지 했고, 이제 실제로 stack두개로 코드 적용하는거 만들어야 함.
		*/
	}
	ft_lstiter(stacks->a, &print_list); // for test
	free_stacks(stacks);
}
