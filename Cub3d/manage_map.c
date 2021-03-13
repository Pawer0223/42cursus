/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:49:57 by taekang           #+#    #+#             */
/*   Updated: 2021/03/14 03:56:10 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		world_map_malloc(int **map, int width, int i)
{
	int j;

	if (!(map[i] = (int *)malloc(sizeof(int) * width)))
	{
		j = 0;
		while (j < i)
			free(map[j++]);
		return (0);
	}
	return (1);
}

int		add_sprite_info(int i, int j, int seq, t_per_sprite **ss)
{
	int free_n;

	free_n = 0;
	if (!(ss[seq] = (t_per_sprite *)malloc(sizeof(t_per_sprite))))
	{
		while (free_n < seq)
			free(ss[free_n++]);
		return (0);
	}
	ss[seq]->x = i + 0.5;
	ss[seq]->y = j + 0.5;
	return (1);
}

int		make_world_map(int **map, int width, t_list *curr, t_per_sprite **ss)
{
	int i;
	int j;
	int	seq;

	seq = 0;
	i = 0;
	while (curr)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * width)))
			return (error_occur(ERROR_MAP_MALLOC));
		j = 0;
		while (*(char *)(curr->content + j))
		{
			map[i][j] = *(char *)(curr->content + j) - '0';
			if (map[i][j] == 5 && !add_sprite_info(i, j, seq++, ss))
				return (error_occur(ERROR_ADD_SPRITE));
			j++;
		}
		while (j < width)
			map[i][j++] = MAP_EMPTY_PASS;
		i++;
		curr = curr->next;
	}
	return (1);
}

int		edge_left_right_check(t_cub3d *info, int limit)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < limit && info->world_map[i][j]
				&& info->world_map[i][j] == MAP_EMPTY_PASS)
			j++;
		if (j >= limit || info->world_map[i][j] == 0)
			return (0);
		j = info->map_width - 1;
		while (j >= 0 && info->world_map[i][j] == MAP_EMPTY_PASS)
			j--;
		if (j < 0 || info->world_map[i][j] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		edge_up_down_check(t_cub3d *info, int limit)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_width)
	{
		j = 0;
		while (j < limit && info->world_map[j][i]
				&& info->world_map[j][i] == MAP_EMPTY_PASS)
			j++;
		if (j >= limit || info->world_map[j][i] == 0)
			return (0);
		j = info->map_height - 1;
		while (j >= 0 && info->world_map[j][i] == MAP_EMPTY_PASS)
			j--;
		if (j < 0 || info->world_map[j][i] == 0)
			return (0);
		i++;
	}
	return (1);
}
