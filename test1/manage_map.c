/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:49:57 by taekang           #+#    #+#             */
/*   Updated: 2021/03/28 18:00:48 by taekang          ###   ########.fr       */
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
			if (map[i][j] == SPRITE && !add_sprite_info(i, j, seq++, ss))
				return (error_occur(ERROR_ADD_SPRITE));
			j++;
		}
		while (j < width)
			map[i][j++] = ' ';
		i++;
		curr = curr->next;
	}
	return (1);
}
