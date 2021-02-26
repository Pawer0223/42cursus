/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:15:40 by taekang           #+#    #+#             */
/*   Updated: 2021/02/23 14:55:43 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./libft/libft.h"

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

void	load_texture(t_cub3d *info)
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

void	set_step_side_dist(t_ray *ray, t_player *info)
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

void	ray_init(t_ray *ray, t_player *info, int x)
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

void	shoot_ray(t_ray *ray, t_player *info)
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

void		draw_init(t_ray *ray, t_player *info, t_draw *draw)
{
	//Calculate height of line to draw on screen
	draw->line_h = (int)(height / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	draw->draw_s = -draw->line_h / 2 + height / 2;
	if(draw->draw_s < 0)
		draw->draw_s = 0;
	draw->draw_e = draw->line_h / 2 + height / 2;
	if(draw->draw_e >= height)
		draw->draw_e = height - 1;
	// texturing calculations
	draw->texture_num = worldMap[ray->map.x][ray->map.y] - 1;
	// calculate value of wallX
	if (ray->side == 0)
		draw->wall_x = info->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		draw->wall_x = info->pos.x + ray->perp_wall_dist * ray->dir.x;
	draw->wall_x -= floor(draw->wall_x);
}

void		draw_wall(t_ray *ray, t_cub3d *info, t_draw *draw, int x)
{
	int y;
	int	tex_x;
	int	tex_y;
	int	color;
	
	draw_init(ray, &info->player, draw);
	draw->step = 1.0 * texHeight / draw->line_h;
	draw->tex_pos = (draw->draw_s - height / 2 + draw->line_h / 2) * draw->step;
	// x coordinate on the texture
	tex_x = (int)(draw->wall_x * (double)texWidth);
	if (ray->side == 0 && ray->dir.x > 0)
		tex_x = texWidth - tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex_x = texWidth - tex_x - 1;	
	y = draw->draw_s;
	while(y < draw->draw_e)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex_y = (int)draw->tex_pos & (texHeight - 1);
		draw->tex_pos += (draw->step);
		color = info->texture[draw->texture_num][texHeight * tex_y + tex_x];
		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}

void	draw_floor(t_ray *ray, t_cub3d *info, t_draw *draw, int x)
{
	// 이거는 floor ceiling 섞어서 표현하는 것.
	//FLOOR CASTING (vertical version, directly after drawing the vertical wall stripe for the current x)
	double floor_w_x, floor_w_y; //x, y position of the floor texel at the bottom of the wall
	//4 different wall directions possible
	if(ray->side == 0 && ray->dir.x > 0)
	{
		floor_w_x = ray->map.x;
		floor_w_y = ray->map.y + draw->wall_x;
	}
	else if(ray->side == 0 && ray->dir.x < 0)
	{
		floor_w_x = ray->map.x + 1.0;
		floor_w_y = ray->map.y + draw->wall_x;
	}
	else if(ray->side == 1 && ray->dir.y > 0)
	{
		floor_w_x = ray->map.x + draw->wall_x;
		floor_w_y = ray->map.y;
	}
	else
	{
		floor_w_x = ray->map.x + draw->wall_x;
		floor_w_y = ray->map.y + 1.0;
	}

	double distWall, distPlayer, currentDist;

	distWall = ray->perp_wall_dist;
	distPlayer = 0.0;

	if (draw->draw_e < 0) 
		draw->draw_e = height; //becomes < 0 when the integer overflows

	//draw the floor from drawEnd to the bottom of the screen
	for(int y = draw->draw_e + 1; y < height; y++)
	{
		currentDist = height / (2.0 * y - height); //you could make a small lookup table for this instead

		double weight = (currentDist - distPlayer) / (distWall - distPlayer);

		double currentFloorX = weight * floor_w_x + (1.0 - weight) * info->player.pos.x;
		double currentFloorY = weight * floor_w_y + (1.0 - weight) * info->player.pos.y;

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

int		draw_buf_fill(t_ray *ray, t_cub3d *info, int x)
{
	t_draw draw;
	draw_wall(ray, info, &draw, x);
	draw_floor(ray, info, &draw, x);
	return (1);
}

// raycasting
void	calc(t_cub3d *info)
{
	//WALL CASTING
	for(int x = 0; x < width; x++)
	{
		t_ray ray;
		ray_init(&ray, &info->player, x);
		shoot_ray(&ray, &info->player);
		draw_buf_fill(&ray, info, x);
	}
}


void	draw(t_cub3d    *info)
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

int	main_loop(t_cub3d *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_player *info)
{
	if (key == K_W)
	{
		if (!worldMap[(int)(info->pos.x + info->dir.x * info->move_speed)][(int)(info->pos.y)])
			info->pos.x += info->dir.x * info->move_speed;
		if (!worldMap[(int)(info->pos.x)][(int)(info->pos.y + info->dir.y * info->move_speed)])
			info->pos.y += info->dir.y * info->move_speed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->pos.x - info->dir.x * info->move_speed)][(int)(info->pos.y)])
			info->pos.x -= info->dir.x * info->move_speed;
		if (!worldMap[(int)(info->pos.x)][(int)(info->pos.y - info->dir.y * info->move_speed)])
			info->pos.y -= info->dir.y * info->move_speed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rot_sppeed) - info->dir.y * sin(-info->rot_sppeed);
		info->dir.y = oldDirX * sin(-info->rot_sppeed) + info->dir.y * cos(-info->rot_sppeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rot_sppeed) - info->plane.y * sin(-info->rot_sppeed);
		info->plane.y = oldPlaneX * sin(-info->rot_sppeed) + info->plane.y * cos(-info->rot_sppeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rot_sppeed) - info->dir.y * sin(info->rot_sppeed);
		info->dir.y = oldDirX * sin(info->rot_sppeed) + info->dir.y * cos(info->rot_sppeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rot_sppeed) - info->plane.y * sin(info->rot_sppeed);
		info->plane.y = oldPlaneX * sin(info->rot_sppeed) + info->plane.y * cos(info->rot_sppeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_cub3d *info, int *texture, char *path, t_img *img)
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

void	player_init(t_player *p)
{
	p->pos.x = 22.0;
	p->pos.y = 11.5;
	p->dir.x = -1.0;
	p->dir.y = 0.0;
	p->plane.x = 0.0;
	p->plane.y = 0.66;
	p->move_speed = 0.05;
	p->rot_sppeed = 0.05;
}

int		texture_init(t_cub3d *info)
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

void	clear_buf(t_cub3d *info)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info->buf[i][j] = 0;
		}
	}
}


int	info_init(t_cub3d *info)
{
	player_init(&info->player);
	clear_buf(info);
	return (1);
}

void	error_print(const char *error_message)
{
	printf("Error\n");
	printf("[%s]\n", error_message);
}

int	main(int argc, const char *argv[])
{
	t_cub3d info;


	// .cub파일 Path받아오기.
	// .cub파일 파싱해서
	// 1. worldMap 저장
	// 2. texture저장
	// 3. floor하고 celing저장 
	// 4. R값 저장.
	

	info.mlx = mlx_init();
	if (!info_init(&info) || !texture_init(&info))
		return (0);
	
	info.win = mlx_new_window(info.mlx, width, height, "cub3d");
	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info.player);
	mlx_loop(info.mlx);
}