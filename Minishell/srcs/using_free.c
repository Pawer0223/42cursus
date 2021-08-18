/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:56:59 by taesan            #+#    #+#             */
/*   Updated: 2021/08/19 03:49:38 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free(void *data)
{
	if (!data)
		return ;
	free(data);
	data = 0;
}

void	split_free(char **data)
{
	int	i;

	if (!data || !*data)
		return ;
	i = 0;
	while (data[i])
		ft_free(data[i++]);
	free(data);
	data = 0;
}

void	clear_all_data(t_info *info)
{
	char	**temp;

	if (info->paths)
	{
		temp = info->paths;
		while (*temp)
		{
			ft_free(*temp);
			temp++;
		}
	}
	if (info->envp)
	{
		temp = info->envp;
		while (*temp)
		{
			ft_free(*temp);
			temp++;
		}
	}
}