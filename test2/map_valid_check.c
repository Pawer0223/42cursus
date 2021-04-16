/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:28:33 by taekang           #+#    #+#             */
/*   Updated: 2021/03/29 15:51:03 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_all_wall(t_cub3d *info, int i, int j, int k)
{
	const int	x[4] = {0, 0, 1, -1};
	const int	y[4] = {1, -1, 0, 0};
	int			possible;

	i += x[k];
	j += y[k];
	possible = 1;
	while (i < info->map_height && j < info->map_width
			&& i >= 0 && j >= 0)
	{
		possible = 0;
		if (info->world_map[i][j] == WALL)
		{
			possible = 1;
			break ;
		}
		else if (info->world_map[i][j] == ' ')
			return (0);
		i += x[k];
		j += y[k];
	}
	if (!possible)
		return (0);
	return (1);
}

int		bearing_wall_check(t_cub3d *info, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (!is_all_wall(info, i, j, k))
			return (0);
		k++;
	}
	return (1);
}

int		map_valid_check(t_cub3d *info)
{
	int	i;
	int	j;
	int value;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			value = info->world_map[i][j];
			if (value == 0)
			{
				if (!bearing_wall_check(info, i, j))
					return (0);
			}
			else if (!(value == WALL || value == SPRITE || value == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
