/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:55:19 by taekang           #+#    #+#             */
/*   Updated: 2021/03/28 12:49:01 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor_w(t_ray *ray, double wall_x, t_d_pair *floor_w)
{
	if (ray->side == 0 && ray->dir.x > 0)
	{
		floor_w->x = ray->map.x;
		floor_w->y = ray->map.y + wall_x;
	}
	else if (ray->side == 0 && ray->dir.x < 0)
	{
		floor_w->x = ray->map.x + 1.0;
		floor_w->y = ray->map.y + wall_x;
	}
	else if (ray->side == 1 && ray->dir.y > 0)
	{
		floor_w->x = ray->map.x + wall_x;
		floor_w->y = ray->map.y;
	}
	else
	{
		floor_w->x = ray->map.x + wall_x;
		floor_w->y = ray->map.y + 1.0;
	}
}

void	set_floor(t_cub3d *info, t_floor *f, t_ray *ray, int y)
{
	f->dist_curr = info->win_height / (2.0 * y - info->win_height);
	f->weight = (f->dist_curr - f->dist_p) / (ray->perp_wall_dist - f->dist_p);
	f->current_f.x = f->weight * f->floor_w.x
					+ (1.0 - f->weight) * info->player.pos.x;
	f->current_f.y = f->weight * f->floor_w.y
					+ (1.0 - f->weight) * info->player.pos.y;
	f->texture_f = info->texture[FLOOR];
	f->texture_c = info->texture[CEILING];
	f->tex_f.x = (int)(f->current_f.x * f->texture_f.width)
					% f->texture_f.width;
	f->tex_f.y = (int)(f->current_f.y * f->texture_f.height)
					% f->texture_f.height;
}

void	fill_floor(t_ray *ray, t_cub3d *info, t_draw *draw, int x)
{
	t_floor	f;
	int		y;
	int		**buf;

	set_floor_w(ray, draw->wall_x, &f.floor_w);
	y = draw->draw_e + 1;
	f.dist_p = 0.0;
	if (draw->draw_e < 0)
		draw->draw_e = info->win_height;
	buf = info->buf;
	while (y < info->win_height)
	{
		set_floor(info, &f, ray, y);
		buf[y][x] = (f.texture_f.texture[f.texture_f.width
							* f.tex_f.y + f.tex_f.x] >> 1) & 8355711;
		buf[info->win_height - y][x] =
							f.texture_c.texture[f.texture_c.width
							* f.tex_f.y + f.tex_f.x];
		y++;
	}
}
