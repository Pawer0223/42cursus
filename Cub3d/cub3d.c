/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:15:40 by taekang           #+#    #+#             */
/*   Updated: 2021/03/14 03:40:10 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_buf(t_cub3d *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->win_height)
	{
		j = 0;
		while (j < info->win_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	raycasting(t_cub3d *info)
{
	int		x;
	t_ray	ray;
	t_draw	draw;

	x = 0;
	while (x < info->win_width)
	{
		shoot_ray(&ray, info, x);
		fill_data(&ray, &draw, info, x);
		x++;
	}
	fill_sprite(info, &info->sprites);
}

void	draw(t_cub3d *info)
{
	int y;
	int x;

	y = 0;
	while (y < info->win_height)
	{
		x = 0;
		while (x < info->win_width)
		{
			info->img.data[y * info->win_width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	clear_buf(info);
}

int		main_loop(t_cub3d *info)
{
	raycasting(info);
	draw(info);
	return (0);
}
