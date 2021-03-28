/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:29:40 by taekang           #+#    #+#             */
/*   Updated: 2021/03/28 14:11:38 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	init_sprite_fill(t_cub3d *info, t_player p, t_sprite_fill *f)
{
	f->inv_det = 1.0 / (p.plane.x * p.dir.y - p.dir.x * p.plane.y);
	f->transform.x = f->inv_det * (p.dir.y * f->spr.x - p.dir.x * f->spr.y);
	f->transform.y = f->inv_det *
					(-p.plane.y * f->spr.x + p.plane.x * f->spr.y);
	f->screen_x = (int)((info->win_width / 2)
					* (1 + f->transform.x / f->transform.y));
	f->v_move_screen = (int)(V_MOVE / f->transform.y);
	f->sprite_h = (int)fabs((info->win_height / f->transform.y) / V_DIV);
	f->draw_start_y = -f->sprite_h / 2 +
					info->win_height / 2 + f->v_move_screen;
	if (f->draw_start_y < 0)
		f->draw_start_y = 0;
	f->draw_end_y = f->sprite_h / 2 + info->win_height / 2
					+ f->v_move_screen;
	if (f->draw_end_y >= info->win_height)
		f->draw_end_y = info->win_height - 1;
	f->sprite_w = (int)fabs((info->win_height / f->transform.y) / U_DIV);
	f->draw_start_x = -f->sprite_w / 2 + f->screen_x;
	if (f->draw_start_x < 0)
		f->draw_start_x = 0;
	f->draw_end_x = f->sprite_w / 2 + f->screen_x;
	if (f->draw_end_x >= info->win_width)
		f->draw_end_x = info->win_width - 1;
}

void	buf_fill(t_cub3d *info, t_sprite_fill *fill, int j, t_tex tex)
{
	int		y;
	int		d;
	int		color;

	y = fill->draw_start_y;
	while (y < fill->draw_end_y)
	{
		d = (y - fill->v_move_screen) * 256 - info->win_height
			* 128 + fill->sprite_h * 128;
		fill->tex.y = ((d * tex.height) / fill->sprite_h) / 256;
		color = tex.texture[tex.width * fill->tex.y + fill->tex.x];
		if ((color & 0x00FFFFFF) != 0)
			info->buf[y][j] = color;
		y++;
	}
}

void	fill(t_cub3d *info, t_sprite *sprites, t_player p)
{
	t_sprite_fill	fill;
	t_tex			tex;
	int				i;
	int				j;

	i = 0;
	tex = info->texture[SPRITE];
	while (i < sprites->cnt)
	{
		fill.spr.x = sprites->info[i]->x - p.pos.x;
		fill.spr.y = sprites->info[i]->y - p.pos.y;
		init_sprite_fill(info, p, &fill);
		j = fill.draw_start_x;
		while (j < fill.draw_end_x)
		{
			fill.tex.x = (int)((256 * (j - (-fill.sprite_w / 2
						+ fill.screen_x)) * tex.width / fill.sprite_w) / 256);
			if (fill.transform.y > 0 && j > 0 && j < info->win_width
				&& fill.transform.y < sprites->z_buffer[j])
				buf_fill(info, &fill, j, tex);
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
