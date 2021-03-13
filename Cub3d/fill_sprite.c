#include "cub3d.h"

void	print(t_per_sprite **sprite) {
	int i;

	i = 0;
	printf("[");
	while (sprite[i])
	{
		printf("%f", sprite[i]->dist);
		i++;
		if (sprite[i])
			printf(", ");
		else
			printf("]\n");
	}
}

void	sort_sprite_desc(t_per_sprite **sprite, int amount)
{
	t_per_sprite	*temp;
	int				i;
	int				j;

	i = 0;
	while (i < amount - 1)
	{
		j = i + 1;
		while (j < amount)
		{
			if (sprite[i]->dist < sprite[j]->dist)
			{
				temp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
 }

void fill(t_cub3d *info, t_sprite *sprites,	t_player p)
{
	t_per_sprite	**sprite;

	sprite = sprites->info;
	int i;
	int	j;

	i = 0;
	while (i < sprites->cnt)
	{
		t_d_pair	spr;
		t_d_pair	transform;
		double		inv_det;

		spr.x = sprite[i]->x - p.pos.x;
		spr.y = sprite[i]->y - p.pos.y;

		inv_det = 1.0 / (p.plane.x * p.dir.y - p.dir.x * p.plane.y);

		transform.x = inv_det * (p.dir.y * spr.x - p.dir.x * spr.y);
		transform.y = inv_det * (-p.plane.y * spr.x + p.plane.x * spr.y);

		int screen_x;
		int v_move_screen;
		int sprite_w;
		int sprite_h;
		int draw_start_y;
		int draw_end_y;
		int draw_start_x;
		int draw_end_x;
		t_tex tex;

		screen_x = (int)((info->win_width / 2) * (1 + transform.x / transform.y));
		v_move_screen = (int)(V_MOVE / transform.y);
		sprite_h = (int)fabs((info->win_height / transform.y) / V_DIV);
		draw_start_y = -sprite_h / 2 + info->win_height / 2 + v_move_screen;

		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_h / 2 + info->win_height / 2 + v_move_screen;
		if (draw_end_y >= info->win_height)
			draw_end_y = info->win_height - 1;

		sprite_w = (int)fabs((info->win_height / transform.y) / U_DIV);
		draw_start_x = -sprite_w / 2 + screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_w / 2 + screen_x;
		if (draw_end_x >= info->win_width)
			draw_end_x = info->win_width - 1;

		tex = info->texture[SPRITE];

		j = draw_start_x;
		while (j < draw_end_x)
		{
			int texX = (int)((256 * (j - (-sprite_w / 2 + screen_x)) * tex.width / sprite_w) / 256);
			if (transform.y > 0 && j > 0 && j < info->win_width && transform.y < sprites->z_buffer[j])
				for (int y = draw_start_y; y < draw_end_y; y++)
				{
					int d = (y - v_move_screen) * 256 - info->win_height * 128 + sprite_h * 128;
					int texY = ((d * tex.height) / sprite_h) / 256;
					int color = tex.texture[tex.width * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						info->buf[y][j] = color;
				}
			j++;
		}
		i++;
	}
}

void	fill_sprite(t_cub3d *info, t_sprite *sprites)
{
	t_per_sprite	**sprite;
	t_player		p;
	int				i;

	p = info->player;
	i = 0;
	sprite = sprites->info;
	while (i < sprites->cnt)
	{
		sprite[i]->dist = ((p.pos.x - sprite[i]->x) * (p.pos.x - sprite[i]->x) 
							+ (p.pos.y - sprite[i]->y) * (p.pos.y - sprite[i]->y));
		i++;
	}
	sort_sprite_desc(sprite, sprites->cnt);
	fill(info, sprites, info->player);
}