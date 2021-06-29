/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:17:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/29 14:41:56 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		split_free(char **data)
{
	int i;

	if (!data || !*data)
		return ;
	i = 0;
	while (data[i])
	{
		if (data[i])
		{
			free(data[i]);
			data[i] = 0;
		}
		i++;
	}
	free(data);
	data = 0;
}