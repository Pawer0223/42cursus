/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:15:40 by taekang           #+#    #+#             */
/*   Updated: 2021/03/12 19:36:42 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* up is test code */
void	clear_buf(t_cub3d *info)
{
	for (int i = 0; i < info->win_height; i++)
	{
		for (int j = 0; j < info->win_width; j++)
		{
			info->buf[i][j] = 0;
		}
	}
}

void	raycasting(t_cub3d *info)
{
	int		x;
	t_ray	ray;
	t_draw 	draw;

	x = 0;
	while(x < info->win_width)
	{
		shoot_ray(&ray, info, x);
		fill_data(&ray, &draw, info, x);
		x++;
	}
	fill_sprite(info, &info->sprites);
}

void	draw(t_cub3d *info)
{
	for (int y = 0; y < info->win_height; y++)
	{
		for (int x = 0; x < info->win_width; x++)
		{
			info->img.data[y * info->win_width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	clear_buf(info);
}

int	main_loop(t_cub3d *info)
{
	raycasting(info);
	draw(info);
	return (0);
}