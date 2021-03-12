/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:29:26 by taekang           #+#    #+#             */
/*   Updated: 2021/03/12 17:08:15 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shoot(t_ray *r, int **map, t_player p)
{
	double dist;

	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
		if (map[r->map.x][r->map.y] > 0 && map[r->map.x][r->map.y] <= SPRITE)
			r->hit = 1;
	}
	if (r->side == 0)
		dist = (r->map.x - p.pos.x + (1 - r->step.x) / 2) / r->dir.x;
	else
		dist = (r->map.y - p.pos.y + (1 - r->step.y) / 2) / r->dir.y;
	r->perp_wall_dist = dist;
}

void	set_step_side_dist(t_ray *ray, t_player p)
{
	int			step_x;
	int			step_y;

	step_x = (ray->dir.x < 0) ? -1 : 1;
	step_y = (ray->dir.y < 0) ? -1 : 1;
	ray->step.x = step_x;
	ray->step.y = step_y;
	if (ray->dir.x < 0)
		ray->side_dist.x = (p.pos.x - ray->map.x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map.x + 1.0 - p.pos.x) * ray->delta_dist.x;
	if (ray->dir.y < 0)
		ray->side_dist.y = (p.pos.y - ray->map.y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map.y + 1.0 - p.pos.y) * ray->delta_dist.y;
}

void	ray_init(t_ray *ray, t_player p, int x, int win_width)
{
	double		camera_x;

	camera_x = 2 * x / (double)win_width - 1;
	ray->camera_x = camera_x;
	ray->dir.x = p.dir.x + p.plane.x * camera_x;
	ray->dir.y = p.dir.y + p.plane.y * camera_x;
	ray->map.x = (int)p.pos.x;
	ray->map.y = (int)p.pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	set_step_side_dist(ray, p);
}

void	shoot_ray(t_ray *ray, t_cub3d *info, int x)
{
	double		dist;

	ray_init(ray, info->player, x, info->win_width);
	shoot(ray, info->world_map, info->player);
}
