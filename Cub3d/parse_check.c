/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:02:04 by taekang           #+#    #+#             */
/*   Updated: 2021/03/28 16:23:52 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		file_format_check(int visited[])
{
	int i;

	i = 0;
	while (i < IDENTIFIERS)
	{
		if (!visited[i])
			return (error_occur(ERROR_MAP_FORMAT));
		i++;
	}
	return (1);
}

int		map_line_check(t_cub3d *info, char *c, int width)
{
	int c_int;

	c_int = *c - '0';
	if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W')
	{
		if (info->player.point)
			return (error_occur(ERROR_POINT_DUPLICATE));
		info->player.point = *c;
		info->player.pos.x = info->map_height + 0.5;
		info->player.pos.y = width + 0.5;
		*c = '0';
		return (1);
	}
	else if ((c_int >= 0 && c_int <= (SPRITE + 1)) || *c == ' ')
	{
		if (c_int == (SPRITE + 1))
			info->sprites.cnt++;
		if (*c == ' ')
			*c += '0';
		return (1);
	}
	else
		return (error_occur(ERROR_MAP_LINE_FORMAT));
}

int		check_identifier(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (RESOLUTION);
	else if (line[0] == 'N' && line[1] == 'O')
		return (NORTH);
	else if (line[0] == 'S' && line[1] == 'O')
		return (SOUTH);
	else if (line[0] == 'W' && line[1] == 'E')
		return (WEST);
	else if (line[0] == 'E' && line[1] == 'A')
		return (EAST);
	else if (line[0] == 'S' && line[1] == ' ')
		return (SPRITE);
	else if (line[0] == 'F' && line[1] == ' ')
		return (FLOOR);
	else if (line[0] == 'C' && line[1] == ' ')
		return (CEILING);
	return (MAP_LINE);
}

int		extension_check(const char *path, const char *extension)
{
	int p_len;
	int e_len;

	p_len = ft_strlen(path);
	e_len = ft_strlen(extension);
	if (p_len < e_len)
		return (0);
	if (ft_strcmp(path + p_len - e_len, extension) != 0)
		return (0);
	return (1);
}
