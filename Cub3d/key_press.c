/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:21:12 by taekang           #+#    #+#             */
/*   Updated: 2021/03/26 18:21:57 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w_s(t_player *p, int **map, double m_speed)
{
	if (!map[(int)(p->pos.x + (p->dir.x * m_speed))][(int)(p->pos.y)])
		p->pos.x += (p->dir.x * m_speed);
	if (!map[(int)(p->pos.x)][(int)(p->pos.y + (p->dir.y * m_speed))])
		p->pos.y += (p->dir.y * m_speed);
}

void	key_d_a(t_player *p, int **map, double r_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(r_speed) - p->dir.y * sin(r_speed);
	p->dir.y = old_dir_x * sin(r_speed) + p->dir.y * cos(r_speed);
	p->plane.x = p->plane.x * cos(r_speed) - p->plane.y * sin(r_speed);
	p->plane.y = old_plane_x * sin(r_speed) + p->plane.y * cos(r_speed);
}

int		key_press(int key, t_cub3d *info)
{
	int			sign;
	t_player	*p;

	p = &info->player;
	sign = (key == K_D || key == K_S) ? -1 : 1;
	if (key == K_W || key == K_S)
		key_w_s(p, info->world_map, p->move_speed * sign);
	if (key == K_D || key == K_A)
		key_d_a(p, info->world_map, p->rot_speed * sign);
	if (key == K_ESC)
		exit(0);
	return (0);
}
