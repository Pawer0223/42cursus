/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/21 03:24:42 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, const char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		return (error_occur(0));
	else
	{
		if (!init_stacks(&stacks, argc, argv))
			return (0);
		test(stacks); // for test
		/* 
			** list만드는 것 까지 했고, 이제 실제로 stack두개로 코드 적용하는거 만들어야 함.
		*/
	}
	free_stacks(stacks);
}
