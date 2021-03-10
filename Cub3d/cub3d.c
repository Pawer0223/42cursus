/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:15:40 by taekang           #+#    #+#             */
/*   Updated: 2021/03/11 02:39:00 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// first => 거리
// second => texture 식별자 ?
typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

struct	Sprite
{
	double		x;
	double		y;
	int			texture;
};

int		spriteOrder[4];
double	spriteDistance[4];

// 바꿔야함 win_width로 
double	zBuffer[700];

// distance 기준으로 내림차순 정렬
void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = i + 1; j < amount; j++)
		{
			if (orders[i].first > orders[j].first)
			{
				tmp.first = orders[i].first;
				tmp.second = orders[i].second;
				orders[i].first = orders[j].first;
				orders[i].second = orders[j].second;
				orders[j].first = tmp.first;
				orders[j].second = tmp.second;
			}
		}
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	//std::vector<std::pair<double, int>> sprites(amount);
	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	//std::sort(sprites.begin(), sprites.end());
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

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

void		draw_init(t_ray *ray, t_cub3d *info, t_draw *draw)
{
	int height;

	height = info->win_height;
	//Calculate height of line to draw on screen
	draw->line_h = (int)(height / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	draw->draw_s = -draw->line_h / 2 + height / 2;
	if (draw->draw_s < 0)
		draw->draw_s = 0;
	draw->draw_e = draw->line_h / 2 + height / 2;
	if (draw->draw_e >= height)
		draw->draw_e = height - 1;
	// texturing calculations
	draw->texture_num = info->world_map[ray->map.x][ray->map.y] - 1;
	// calculate value of wallX
	if (ray->side == 0)
		draw->wall_x = info->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		draw->wall_x = info->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	draw->wall_x -= floor(draw->wall_x);
}

void		draw_wall(t_ray *ray, t_cub3d *info, t_draw *draw, int x)
{
	int y;
	int	tex_x;
	int	tex_y;
	int	color;
	
	draw_init(ray, info, draw);
	t_tex tex = info->texture[draw->texture_num];
	draw->step = 1.0 * tex.height / draw->line_h;
	draw->tex_pos = (draw->draw_s - info->win_height / 2 + draw->line_h / 2) * draw->step;
	// x coordinate on the texture
	tex_x = (int)(draw->wall_x * (double)tex.width);
	if (ray->side == 0 && ray->dir.x > 0)
		tex_x = tex.width - tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex_x = tex.width - tex_x - 1;
	y = draw->draw_s;
	while(y < draw->draw_e)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex_y = (int)draw->tex_pos & (tex.height - 1);
		draw->tex_pos += (draw->step);
		color = tex.texture[tex.height * tex_y + tex_x];
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
		draw->draw_e = info->win_height; //becomes < 0 when the integer overflows

	//draw the floor from drawEnd to the bottom of the screen
	for(int y = draw->draw_e + 1; y < info->win_height; y++)
	{
		currentDist = info->win_height / (2.0 * y - info->win_height); //you could make a small lookup table for this instead

		double weight = (currentDist - distPlayer) / (distWall - distPlayer);

		double currentFloorX = weight * floor_w_x + (1.0 - weight) * info->player.pos.x;
		double currentFloorY = weight * floor_w_y + (1.0 - weight) * info->player.pos.y;

		int floorTexX, floorTexY;

		t_tex texFloor;
		t_tex texCeling;

		texFloor = info->texture[FLOOR];
		texCeling = info->texture[CEILING];

		floorTexX = (int)(currentFloorX * texFloor.width) % texFloor.width;
		floorTexY = (int)(currentFloorY * texFloor.height) % texFloor.height;

		//int checkerBoardPattern = ((int)(currentFloorX) + (int)(currentFloorY)) % 2;
		// if(checkerBoardPattern == 0) floorTexture = 3;
		// else floorTexture = 4;

		//floor
		info->buf[y][x] = (texFloor.texture[texFloor.width * floorTexY + floorTexX] >> 1) & 8355711;
		//ceiling (symmetrical!)
		info->buf[info->win_height - y][x] = texCeling.texture[texCeling.width * floorTexY + floorTexX];
	}
}

void	draw_sprite(t_cub3d *info, t_sprite *sprites)
{
	t_player *p = &info->player;
	t_d_pair	**sprite;

	sprite = sprites->pos;
	double a = sprite[0]->x;

	//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < sprites->cnt; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((p->pos.x - sprite[i]->x) * (p->pos.x - sprite[i]->x) + (p->pos.y - sprite[i]->y) * (p->pos.y - sprite[i]->y)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, sprites->cnt);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < sprites->cnt; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = sprite[spriteOrder[i]]->x - p->pos.x;
		double spriteY = sprite[spriteOrder[i]]->y - p->pos.y;

		double invDet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y); //required for correct matrix multiplication

		double transformX = invDet * (p->dir.y * spriteX - p->dir.x * spriteY);
		double transformY = invDet * (-p->plane.y * spriteX + p->plane.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((info->win_width / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((info->win_height / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if(drawEndY >= info->win_height) drawEndY = info->win_height - 1;
		// printf("drawStartY : %d, drawEndY : %d\n", drawStartY, drawEndY);


		//calculate width of the sprite
		int spriteWidth = (int)fabs((info->win_height / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= info->win_width) drawEndX = info->win_width - 1;

		// printf("drawStartX : %d, drawEndX : %d\n", drawStartX, drawEndX);

		t_tex tex = info->texture[SPRITE];
		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * tex.width / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			// printf("transformY : %f, zBuffer[stripe] : %f\n", transformY, zBuffer[stripe]);
			if(transformY > 0 && stripe > 0 && stripe < info->win_width && transformY < zBuffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - info->win_height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * tex.height) / spriteHeight) / 256;
				int color = tex.texture[tex.width * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
}

void		draw_buf_fill(t_ray *ray, t_cub3d *info, int x)
{
	t_draw draw;
	
	draw_wall(ray, info, &draw, x);
	draw_floor(ray, info, &draw, x);
}

// raycasting
void	calc(t_cub3d *info)
{
	int		x;
	t_ray	ray;

	x = 0;
	//WALL CASTING
	while(x < info->win_width)
	{
		ray_init(&ray, info, x);
		shoot_ray(&ray, info);
		zBuffer[x] = ray.perp_wall_dist; //perpendicular distance is used
		draw_buf_fill(&ray, info, x);
		x++;
	}
	draw_sprite(info, &info->sprites);
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
}

int	main_loop(t_cub3d *info)
{
	calc(info);
	draw(info);
	clear_buf(info);
	return (0);
}

int	key_press(int key, t_cub3d *info)
{
	int **map;
	t_player p;

	map = info->world_map;
	p = info->player;
	if (key == K_W)
	{
		if (!map[(int)(p.pos.x + p.dir.x * p.move_speed)][(int)(p.pos.y)])
			p.pos.x += p.dir.x * p.move_speed;
		if (!map[(int)(p.pos.x)][(int)(p.pos.y + p.dir.y * p.move_speed)])
			p.pos.y += p.dir.y * p.move_speed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!map[(int)(p.pos.x - p.dir.x * p.move_speed)][(int)(p.pos.y)])
			p.pos.x -= p.dir.x * p.move_speed; 
		if (!map[(int)(p.pos.x)][(int)(p.pos.y - p.dir.y * p.move_speed)])
			p.pos.y -= p.dir.y * p.move_speed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p.dir.x;
		p.dir.x = p.dir.x * cos(-p.rot_sppeed) - p.dir.y * sin(-p.rot_sppeed);
		p.dir.y = oldDirX * sin(-p.rot_sppeed) + p.dir.y * cos(-p.rot_sppeed);
		double oldPlaneX = p.plane.x;
		p.plane.x = p.plane.x * cos(-p.rot_sppeed) - p.plane.y * sin(-p.rot_sppeed);
		p.plane.y = oldPlaneX * sin(-p.rot_sppeed) + p.plane.y * cos(-p.rot_sppeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p.dir.x;
		p.dir.x = p.dir.x * cos(p.rot_sppeed) - p.dir.y * sin(p.rot_sppeed);
		p.dir.y = oldDirX * sin(p.rot_sppeed) + p.dir.y * cos(p.rot_sppeed);
		double oldPlaneX = p.plane.x;
		p.plane.x = p.plane.x * cos(p.rot_sppeed) - p.plane.y * sin(p.rot_sppeed);
		p.plane.y = oldPlaneX * sin(p.rot_sppeed) + p.plane.y * cos(p.rot_sppeed);
	}
	info->player = p;
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	error_print(const char *error_message)
{
	printf("Error\n");
	printf("[%s]\n", error_message);
}