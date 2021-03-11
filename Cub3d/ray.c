#include "cub3d.h"

void	set_step_side_dist(t_ray *ray, t_cub3d *info)
{
	t_player p;

	p = info->player;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (p.pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - p.pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (p.pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - p.pos.y) * ray->delta_dist.y;
	}
}

void	ray_init(t_ray *ray, t_cub3d *info, int x)
{
	t_player	p;
	double		camera_x;

	p = info->player;
	camera_x = 2 * x / (double)info->win_width - 1;
	ray->camera_x = camera_x;
	ray->dir.x = p.dir.x + p.plane.x * camera_x;
	ray->dir.y = p.dir.y + p.plane.y * camera_x;
	ray->map.x = (int)p.pos.x;
	ray->map.y = (int)p.pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	set_step_side_dist(ray, info);
}

void	shoot_ray(t_ray *ray, t_cub3d *info)
{
	while (ray->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		//Check if ray has hit a wall
		if (info->world_map[ray->map.x][ray->map.y] > 0 && info->world_map[ray->map.x][ray->map.y] <= SPRITE)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - info->player.pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - info->player.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
}
