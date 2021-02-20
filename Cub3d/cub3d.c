/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:15:40 by taekang           #+#    #+#             */
/*   Updated: 2021/02/21 02:26:44 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	worldMap[mapWidth][mapHeight] =
									{
										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
							  			{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
									};

void	set_step_side_dist(t_ray *ray, t_info *info)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (info->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - info->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (info->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - info->pos.y) * ray->delta_dist.y;
	}	
}

void	ray_init(t_ray *ray, t_info *info, int x)
{
	double camera_x = 2 * x / (double)width - 1;
	ray->camera_x = camera_x;
	ray->dir.x = info->dir.x + info->plane.x * camera_x;
	ray->dir.y = info->dir.y + info->plane.y * camera_x;
	ray->map.x = (int)info->pos.x;
	ray->map.y = (int)info->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	set_step_side_dist(ray, info);
}

void	shoot_ray(t_ray *ray, t_info *info)
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
		if (worldMap[ray->map.x][ray->map.y] > 0) 
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - info->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - info->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
}

void		draw_wall(t_ray *ray, t_info *info, int x)
{
			//Calculate height of line to draw on screen
	int lineHeight = (int)(height / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	info->draw.draw_s = -lineHeight / 2 + height / 2;
	if(info->draw.draw_s < 0)
		info->draw.draw_s = 0;
	info->draw.draw_e = lineHeight / 2 + height / 2;
	if(info->draw.draw_e >= height)
		info->draw.draw_e = height - 1;
	// texturing calculations
	int texNum = worldMap[ray->map.x][ray->map.y] - 1;
	// calculate value of wallX
	if (ray->side == 0)
		info->draw.wall_x = info->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		info->draw.wall_x = info->pos.x + ray->perp_wall_dist * ray->dir.x;
	info->draw.wall_x -= floor(info->draw.wall_x);

	// x coordinate on the texture
	int texX = (int)(info->draw.wall_x * (double)texWidth);
	if (ray->side == 0 && ray->dir.x > 0)
		texX = texWidth - texX - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		texX = texWidth - texX - 1;

	// How much to increase the texture coordinate perscreen pixel
	double step = 1.0 * texHeight / lineHeight;

	// Starting texture coordinate
	double texPos = (info->draw.draw_s - height / 2 + lineHeight / 2) * step;

	for (int y = info->draw.draw_s; y < info->draw.draw_e; y++)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;

		int color = info->texture[texNum][texHeight * texY + texX];

		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (ray->side == 1)
			color = (color >> 1) & 8355711;

		info->buf[y][x] = color;
	}
}

void	draw_floor(t_ray *ray, t_info *info, int x)
{
	// 이거는 floor ceiling 섞어서 표현하는 것.
	//FLOOR CASTING (vertical version, directly after drawing the vertical wall stripe for the current x)
	double floor_w_x, floor_w_y; //x, y position of the floor texel at the bottom of the wall
	t_draw draw;

	draw = info->draw;

	//4 different wall directions possible
	if(ray->side == 0 && ray->dir.x > 0)
	{
		floor_w_x = ray->map.x;
		floor_w_y = ray->map.y + draw.wall_x;
	}
	else if(ray->side == 0 && ray->dir.x < 0)
	{
		floor_w_x = ray->map.x + 1.0;
		floor_w_y = ray->map.y + draw.wall_x;
	}
	else if(ray->side == 1 && ray->dir.y > 0)
	{
		floor_w_x = ray->map.x + draw.wall_x;
		floor_w_y = ray->map.y;
	}
	else
	{
		floor_w_x = ray->map.x + draw.wall_x;
		floor_w_y = ray->map.y + 1.0;
	}

	double distWall, distPlayer, currentDist;

	distWall = ray->perp_wall_dist;
	distPlayer = 0.0;

	if (draw.draw_e < 0) 
		draw.draw_e = height; //becomes < 0 when the integer overflows

	//draw the floor from drawEnd to the bottom of the screen
	for(int y = draw.draw_e + 1; y < height; y++)
	{
		currentDist = height / (2.0 * y - height); //you could make a small lookup table for this instead

		double weight = (currentDist - distPlayer) / (distWall - distPlayer);

		double currentFloorX = weight * floor_w_x + (1.0 - weight) * info->pos.x;
		double currentFloorY = weight * floor_w_y + (1.0 - weight) * info->pos.y;

		int floorTexX, floorTexY;
		floorTexX = (int)(currentFloorX * texWidth) % texWidth;
		floorTexY = (int)(currentFloorY * texHeight) % texHeight;

		int checkerBoardPattern = ((int)(currentFloorX) + (int)(currentFloorY)) % 2;
		int floorTexture;
		if(checkerBoardPattern == 0) floorTexture = 3;
		else floorTexture = 4;

		//floor
		info->buf[y][x] = (info->texture[floorTexture][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
		//ceiling (symmetrical!)
		info->buf[height - y][x] = info->texture[6][texWidth * floorTexY + floorTexX];
	}
}

// raycasting
void	calc(t_info *info)
{
	//WALL CASTING
	for(int x = 0; x < width; x++)
	{
		t_ray ray;

		ray_init(&ray, info, x);
		shoot_ray(&ray, info);
		draw_wall(&ray, info, x);
		draw_floor(&ray, info, x);
	}
}


void	draw(t_info    *info)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			info->img.data[y * width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (!worldMap[(int)(info->pos.x + info->dir.x * info->moveSpeed)][(int)(info->pos.y)])
			info->pos.x += info->dir.x * info->moveSpeed;
		if (!worldMap[(int)(info->pos.x)][(int)(info->pos.y + info->dir.y * info->moveSpeed)])
			info->pos.y += info->dir.y * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->pos.x - info->dir.x * info->moveSpeed)][(int)(info->pos.y)])
			info->pos.x -= info->dir.x * info->moveSpeed;
		if (!worldMap[(int)(info->pos.x)][(int)(info->pos.y - info->dir.y * info->moveSpeed)])
			info->pos.y -= info->dir.y * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rotSpeed) - info->dir.y * sin(-info->rotSpeed);
		info->dir.y = oldDirX * sin(-info->rotSpeed) + info->dir.y * cos(-info->rotSpeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rotSpeed) - info->plane.y * sin(-info->rotSpeed);
		info->plane.y = oldPlaneX * sin(-info->rotSpeed) + info->plane.y * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rotSpeed) - info->dir.y * sin(info->rotSpeed);
		info->dir.y = oldDirX * sin(info->rotSpeed) + info->dir.y * cos(info->rotSpeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rotSpeed) - info->plane.y * sin(info->rotSpeed);
		info->plane.y = oldPlaneX * sin(info->rotSpeed) + info->plane.y * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/deer.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

void	pair_init(t_info *info)
{
	info->pos.x = 22.0;
	info->pos.y = 11.5;
	info->dir.x = -1.0;
	info->dir.y = 0.0;
	info->plane.x = 0.0;
	info->plane.y = 0.66;
}

void	clear_buf(t_info *info)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info->buf[i][j] = 0;
		}
	}
}

int		texture_init(t_info *info)
{

	if (!(info->texture = (int **)malloc(sizeof(int *) * 8)))
		return (0);
	for (int i = 0; i < 8; i++)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (0);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info->texture[i][j] = 0;
		}
	}
	load_texture(info);
	return (1);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	pair_init(&info);
	clear_buf(&info);
	if (!texture_init(&info))
		return (0);

	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	
	info.win = mlx_new_window(info.mlx, width, height, "cub3d");
	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}