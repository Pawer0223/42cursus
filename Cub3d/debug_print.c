/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:41:03 by taekang           #+#    #+#             */
/*   Updated: 2021/03/14 15:43:47 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_list(void *content)
{
	printf("[%s]\n", content);
}

void	print_world_map(t_cub3d *info)
{
	int i;
	int j;

	printf("### print_world_map ### \n");
	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			printf("%d", info->world_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_sprites(int cnt, t_per_sprite **pos)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		printf("[%d] sprite => x : %f, y : %f\n", i, pos[i]->x, pos[i]->y);
		i++;
	}
}

void	to_string(t_cub3d *info)
{
	printf("win_width : %d\n", info->win_width);
	printf("win_height : %d\n", info->win_height);
	printf("map_width : %d\n", info->map_width);
	printf("map_height : %d\n", info->map_height);
	printf("sprite_num : %d\n", info->sprites.cnt);
	printf("### map_buf ###\n");
	ft_lstiter(info->map_buf, &print_list);
	printf("### sprite info ###\n");
	print_sprites(info->sprites.cnt, info->sprites.info);
	printf("### player ###\n");
	printf("pos.x : %f, pos.y : %f\n", info->player.pos.x, info->player.pos.y);
	printf("dir.x : %f, dir.y : %f\n", info->player.dir.x, info->player.dir.y);
	printf("plane.x : %f, plane.y : %f\n",
		info->player.plane.x, info->player.plane.y);
	printf("point : %c\n", info->player.point);
	printf("move_speed : %f, rot_speed : %f\n",
		info->player.move_speed, info->player.move_speed);
	print_world_map(info);
}
