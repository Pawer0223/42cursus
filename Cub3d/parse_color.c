/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:48:34 by taekang           #+#    #+#             */
/*   Updated: 2021/03/14 15:49:00 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_color(char c, int *color, int *value, int *seq)
{
	if (c && ft_isdigit(c))
		*value = *value * 10 + c - '0';
	else if (c == ',' || (!c && *value >= 0))
	{
		if (c < 0 || *value > 255)
			return (error_occur(ERROR_RGB_VALUE));
		*color = *color | (*value << (16 - (*seq * 8)));
		*value = 0;
		*seq += 1;
	}
	else
		return ((error_occur(ERROR_RGB_FORMAT)));
	return (1);
}

int		parse_color(t_cub3d *info, int id, char *line)
{
	int value;
	int seq;
	int color;

	line += 2;
	value = 0;
	seq = 0;
	color = 0;
	while (*line)
	{
		if (!set_color(*line, &color, &value, &seq))
			return (0);
		line++;
	}
	if (seq != 2 || !set_color(*line, &color, &value, &seq))
		return ((error_occur(ERROR_RGB_FORMAT)));
	info->texture[id].width = 64;
	info->texture[id].height = 64;
	if (!(fill_texture(&info->texture[id], &color, 1)))
		return (error_occur(ERROR_FILL_TEXTURE));
	return (1);
}
