/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:10:23 by taekang           #+#    #+#             */
/*   Updated: 2021/03/26 18:24:16 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_id_r(t_cub3d *info, char *line)
{
	int i;

	i = 1;
	info->win_width = get_int_value(line, &i);
	info->win_height = get_int_value(line, &i);
	if (info->win_width == -1 || info->win_height == -1)
		return (0);
	i = 0;
	return (1);
}

int		parse_and_load_texture(t_cub3d *info, int id, char *line)
{
	int		i;
	t_img	img;

	i = (id >= SPRITE) ? 2 : 3;
	if (!load_image(info, &info->texture[id], (line + i), &img))
		return (error_occur(ERROR_TEXTURE_LOAD));
	return (1);
}

int		parse_map(t_cub3d *info, char *line)
{
	int		i;
	int		r;
	int		width;
	t_list	*next;

	i = 0;
	width = 0;
	r = 0;
	while (line[i])
	{
		if (!(r = map_line_check(info, &line[i], width)))
			return (0);
		width++;
		i++;
	}
	info->map_width = ft_max(info->map_width, width);
	info->map_height++;
	if (!(next = ft_lstnew(line)))
	{
		ft_lstclear(&info->map_buf, &del_line);
		return (error_occur(ERROR_MAP_BUF_MALLOC));
	}
	ft_lstadd_back(&info->map_buf, next);
	return (1);
}

int		parse_line(t_cub3d *info, char *line, int visited[])
{
	int id;

	if (is_empty_line(line))
		return (1);
	id = check_identifier(line);
	if (id != MAP_LINE && (visited[id] || visited[MAP_LINE]))
		return (error_occur(ERROR_FILE_PARSE));
	visited[id] = 1;
	if (id == RESOLUTION)
		return (parse_id_r(info, line));
	else if (id >= NORTH && id <= SPRITE)
		return (parse_and_load_texture(info, id, line));
	else if (id == FLOOR || id == CEILING)
		return (parse_color(info, id, line));
	if (id == MAP_LINE && !visited[id])
	{
		if (!(info->map_buf = ft_lstnew(line)))
			return (error_occur(ERROR_BUF_MALLOC));
		visited[id] = 1;
	}
	return (parse_map(info, ft_strdup(line)));
}

int		parse_file(t_cub3d *info, const char *path)
{
	int		c_fd;
	int		r;
	char	*line;
	int		visited[IDENTIFIERS];

	ft_bzero(visited, (IDENTIFIERS * sizeof(int)));
	if (!extension_check(path, ".cub"))
		return (error_occur(ERROR_EXTENSION));
	if ((c_fd = open(path, O_RDONLY)) < 0)
		return (error_occur(ERROR_FILE_NOT_EXIST));
	r = 1;
	while (r && get_next_line(c_fd, &line))
	{
		r = parse_line(info, line, visited);
		free(line);
	}
	if (!r || !parse_line(info, line, visited))
		return (0);
	if (!info->player.point)
		return (error_occur(ERROR_MAP_FORMAT_NSEW));
	free(line);
	close(c_fd);
	return (1);
}
