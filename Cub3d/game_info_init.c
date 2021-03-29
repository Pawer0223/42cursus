/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:45:14 by taekang           #+#    #+#             */
/*   Updated: 2021/03/29 19:13:01 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_player *p)
{
	char point;

	point = p->point;
	if (point == 'N' || point == 'S')
	{
		p->dir.x = (point == 'S') ? 0.99 : -0.99;
		p->dir.y = 0.0;
		p->plane.x = 0.0;
		p->plane.y = (point == 'S') ? -0.66 : 0.66;
	}
	else if (point == 'E' || point == 'W')
	{
		p->dir.x = 0.0;
		p->dir.y = (point == 'W') ? -1.0 : 1.0;
		p->plane.x = (point == 'W') ? -0.66 : 0.66;
		p->plane.y = 0.0;
	}
	p->move_speed = 0.5;
	p->rot_speed = 0.1;
}

void	cub3d_free(t_cub3d *info)
{
	int i;

	i = 0;
	while (i < info->win_height)
		free(info->buf[i++]);
	free(info->buf);
	i = 0;
	while (i < info->sprites.cnt)
		free(info->sprites.info[i++]);
	free(info->sprites.z_buffer);
	free(info->sprites.info);
	i = 0;
	while (i < info->map_height)
		free(info->world_map[i++]);
}

int		cub3d_init(t_cub3d *info)
{
	int i;

	if (!(info->buf = (int **)malloc(sizeof(int *) * info->win_height)))
		return (error_occur(ERROR_BUF_MALLOC));
	i = 0;
	while (i < info->win_height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * info->win_width)))
			return (error_occur(ERROR_BUF_MALLOC));
		i++;
	}
	return (1);
}

void	check_window_size(t_cub3d *info)
{
	if (info->win_height > MAX_X)
		info->win_height = MAX_X;
	if (info->win_width > MAX_Y)
		info->win_width = MAX_Y;
	if (info->win_height < MIN_X)
		info->win_height = MIN_X;
	if (info->win_width < MIN_Y)
		info->win_width = MIN_Y;
}

int		game_info_init(t_cub3d *info, t_sprite *s)
{
	check_window_size(info);
	if (!cub3d_init(info))
		return (0);
	if (!(s->info = (t_per_sprite **)
						malloc(sizeof(t_per_sprite *) * s->cnt)))
		return (error_occur(ERROR_SPRITES_MALLOC));
	if (!(s->z_buffer = (double *)malloc(sizeof(double) * info->win_width)))
		return (error_occur(ERROR_SPRITES_MALLOC));
	if (!(info->world_map = (int **)malloc(sizeof(int *) * info->map_height)))
		return (error_occur(ERROR_SPRITES_MALLOC));
	if (!make_world_map(info->world_map,
			info->win_width, info->map_buf, s->info))
		return (error_occur(ERROR_MAP_MALLOC));
	ft_lstclear(&info->map_buf, &del_line);
	if (!map_valid_check(info))
		return (error_occur(ERROR_MAP_FORMAT));
	player_init(&info->player);
	return (1);
}
