/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:42:58 by taekang           #+#    #+#             */
/*   Updated: 2021/03/28 15:53:58 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		more_dark(int color)
{
	return ((color >> 1) & 8355711);
}

void	fill_wall(t_ray *ray, t_cub3d *info, t_draw *d, int x)
{
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;
	t_tex	tex;

	tex = info->texture[ray->eye];
	d->step = 1.0 * tex.height / d->line_h;
	d->tex_pos = (d->draw_s - info->win_height / 2 + d->line_h / 2) * d->step;
	tex_x = (int)(d->wall_x * (double)tex.width);
	if (ray->side == 0 && ray->dir.x > 0)
		tex_x = tex.width - tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex_x = tex.width - tex_x - 1;
	y = d->draw_s;
	while (y < d->draw_e)
	{
		tex_y = (int)d->tex_pos & (tex.height - 1);
		d->tex_pos += (d->step);
		color = tex.texture[tex.height * tex_y + tex_x];
		if (ray->side == 1)
			color = more_dark(color);
		info->buf[y][x] = color;
		y++;
	}
}

void	draw_init(t_ray *ray, t_cub3d *info, t_draw *draw)
{
	int height;

	height = info->win_height;
	draw->line_h = (int)(height / ray->perp_wall_dist);
	draw->draw_s = -draw->line_h / 2 + height / 2;
	if (draw->draw_s < 0)
		draw->draw_s = 0;
	draw->draw_e = draw->line_h / 2 + height / 2;
	if (draw->draw_e >= height)
		draw->draw_e = height - 1;
	if (ray->side == 0)
		draw->wall_x = info->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		draw->wall_x = info->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	draw->wall_x -= floor(draw->wall_x);
}

void	fill_data(t_ray *ray, t_draw *draw, t_cub3d *info, int x)
{
	draw_init(ray, info, draw);
	fill_wall(ray, info, draw, x);
	fill_floor(ray, info, draw, x);
}
