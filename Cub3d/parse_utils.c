/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:05:27 by taekang           #+#    #+#             */
/*   Updated: 2021/03/29 14:36:09 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_texture(t_tex *tex, int *data, int is_f_c)
{
	int x;
	int y;

	if (!(tex->texture = (int *)malloc(sizeof(int) * tex->width * tex->height)))
		return (0);
	ft_bzero(tex->texture, tex->width * tex->height * sizeof(int));
	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			if (is_f_c)
				tex->texture[tex->width * y + x] = *data;
			else
				tex->texture[tex->width * y + x] = data[tex->width * y + x];
			x++;
		}
		y++;
	}
	return (1);
}

int		get_int_value(const char *line, int *i)
{
	int value;

	value = 0;
	while (line[*i] && line[*i] == ' ')
		*i += 1;
	while (line[*i])
	{
		if (line[*i] == ' ')
			return (value);
		if (!ft_isdigit(line[*i]))
			return (-1);
		else
			value = (value * 10) + line[*i] - '0';
		*i += 1;
	}
	return (value);
}

void	line_trim(char *line)
{
	int i;
	int	end;

	end = ft_strlen(line) - 1;
	i = end;
	while (i >= 0)
	{
		if (line[i] != ' ')
			break ;
		i--;
	}
	line[i + 1] = 0;
}

int		load_image(t_cub3d *info, t_tex *tex, char *path, t_img *img)
{
	if (!(img->img =
			mlx_xpm_file_to_image(info->mlx, path, &tex->width, &tex->height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian)))
		return (0);
	if (!(fill_texture(tex, img->data, 0)))
		return (error_occur(ERROR_FILL_TEXTURE));
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}
