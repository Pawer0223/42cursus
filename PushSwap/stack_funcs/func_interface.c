/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:38:20 by taesan            #+#    #+#             */
/*   Updated: 2021/05/20 20:23:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_funcs.h"

void	push(t_stacks *stacks, char name)
{
	char	minus;
	int		res;

	res = 0;
	minus = (name == A) ? B : A;
	if (name == A)
		res = pa(stacks);
	else if (name == B)
		res = pb(stacks);
	if (res)
	{
		size_add(stacks, name);
		size_minus(stacks, minus);
	}
}