/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/15 21:58:58 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_start(t_cub3d *info)
{
	info->win = mlx_new_window(info->mlx,
				info->win_width, info->win_height, "cub3d");
	info->img.img = mlx_new_image(info->mlx,
				info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
				&info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
}

int		main(int argc, const char *argv[])
{
	t_cub3d	info;
	int		r;

	ft_bzero(&info, sizeof(t_cub3d));
	info.mlx = mlx_init();
	if (argc == 2)
		r = parse_file(&info, argv[1]);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[1], "--save") != 0)
			return (error_occur(ERROR_PARAM));
		// save 옵션 저장 해주기. bmp파일저장
		r = parse_file(&info, argv[2]);
	}
	else
		return (error_occur(ERROR_PARAM));
	if (!r)
		exit(1);
	if (!game_info_init(&info, &info.sprites))
		exit(1);
	raycasting_start(&info);
}
