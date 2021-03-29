/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:40:00 by taekang           #+#    #+#             */
/*   Updated: 2021/03/24 14:33:11 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color(t_cub3d *info, int x, int y)
{
	int	rgb;
	int	color;

	color = info->buf[y][x];
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int		write_bmp_data(int file, t_cub3d *info, int pad)
{
	const unsigned char		zero[3] = {0, 0, 0};
	int						color;
	int						y;
	int						x;

	y = info->win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->win_width)
		{
			color = get_color(info, x, y);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int		write_bmp_header(int fd, int filesize, t_cub3d *info)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_in_char(bmpfileheader + 18, info->win_width);
	set_int_in_char(bmpfileheader + 22, info->win_height);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

int		save_bmp(t_cub3d *info)
{
	int		filesize;
	int		file;
	int		pad;

	raycasting(info);
	pad = (4 - ((int)info->win_width * 3) % 4) % 4;
	filesize = 54 + (3 * (info->win_width + pad) * info->win_height);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return (error_occur(ERROR_SAVE));
	if (!write_bmp_header(file, filesize, info))
		return (error_occur(ERROR_SAVE));
	if (!write_bmp_data(file, info, pad))
		return (error_occur(ERROR_SAVE));
	close(file);
	return (1);
}
