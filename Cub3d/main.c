/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/14 03:50:35 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*
	print functions
*/

void print_list(void *content)
{
	printf("[%s]\n", content);
}

void print_world_map(t_cub3d *info)
{
	int i;
	int j;

	printf("### print_world_map ### \n");
	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			printf("%d", info->world_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void print_sprites(int cnt, t_per_sprite **pos)
{
	int i;
	i = 0;
	while (i < cnt)
	{
		printf("[%d] sprite => x : %f, y : %f\n", i, pos[i]->x, pos[i]->y);
		i++;
	}
}

void to_string(t_cub3d *info)
{
	printf("win_width : %d\n", info->win_width);
	printf("win_height : %d\n", info->win_height);
	printf("map_width : %d\n", info->map_width);
	printf("map_height : %d\n", info->map_height);
	printf("sprite_num : %d\n", info->sprites.cnt);
	printf("### map_buf ###\n");

	ft_lstiter(info->map_buf, &print_list);
	printf("### sprite info ###\n");
	print_sprites(info->sprites.cnt, info->sprites.info);
	printf("### player ###\n");
	printf("pos.x : %f, pos.y : %f\n", info->player.pos.x, info->player.pos.y);
	printf("dir.x : %f, dir.y : %f\n", info->player.dir.x, info->player.dir.y);
	printf("plane.x : %f, plane.y : %f\n", info->player.plane.x, info->player.plane.y);
	printf("point : %c\n", info->player.point);
	printf("move_speed : %f, rot_speed : %f\n", info->player.move_speed, info->player.move_speed);
	print_world_map(info);
}

int error_occur(const char *error_message)
{
	printf("Error\n");
	printf(": [%s]\n", error_message);
	return (0);
}

int check_identifier(char *line)
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

int extension_check(const char *path, const char *extension)
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

int get_int_value(const char *line, int *i)
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

int parse_id_r(t_cub3d *info, char *line)
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

int	fill_texture(t_tex *tex, int *data, int is_f_c)
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

int load_image(t_cub3d *info, t_tex *tex, char *path, t_img *img)
{

	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &tex->width, &tex->height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian)))
		return (0);
	if (!(fill_texture(tex, img->data, 0)))
		return (error_occur(ERROR_FILL_TEXTURE));
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int parse_and_load_texture(t_cub3d *info, int id, char *line)
{
	int		i;
	t_img	img;

	i = (id == SPRITE) ? 2 : 3;
	if (!load_image(info, &info->texture[id], (line + i), &img))
		return (error_occur(ERROR_TEXTURE_LOAD));
	return (1);
}

int ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) || line[i] != ' ' || line[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

#define tex_w 1
#define tex_h 1

int set_color(char c, int *color, int *value, int *seq)
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

int parse_color(t_cub3d *info, int id, char *line)
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
	if (seq != 2 || !set_color(*line, &color, &value, &seq)) {
		return ((error_occur(ERROR_RGB_FORMAT)));
	}
	info->texture[id].width = 64;
	info->texture[id].height = 64;
	if (!(fill_texture(&info->texture[id], &color, 1)))
		return (error_occur(ERROR_FILL_TEXTURE));
	return (1);
}

int	map_line_check(t_cub3d *info, char c, int width)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (info->player.point)
			return error_occur(ERROR_POINT_DUPLICATE);
		info->player.point = c;
		info->player.pos.x = info->map_height + 0.5;
		info->player.pos.y = width + 0.5;
		return (2);
	}
	else if ((c >= '0' && c <= '5') || c == ' ')
	{
		if (c == '5')
			info->sprites.cnt++;
		return (1);
	}
	else
		return error_occur(ERROR_MAP_LINE_FORMAT);
}

int ft_max(int a, int b)
{
	return (a > b) ? a : b;
}


int parse_map(t_cub3d *info, char *line)
{
	int i;
	int r;
	int width;
	t_list *next;

	i = 0;
	width = 0;
	r = 0;
	while (line[i])
	{
		if (!(r = map_line_check(info, line[i], width)))
			return (0);
		if (r == 2)
			line[i] = '0';
		if (line[i] == ' ')
			line[i] = '9';
		width++;
		i++;
	}
	info->map_width = ft_max(info->map_width, width);
	info->map_height++;
	if (!(next = ft_lstnew(line)))
	{
		ft_lstclear(&info->map_buf, &del_line);
		return error_occur(ERROR_MAP_BUF_MALLOC);
	}
	ft_lstadd_back(&info->map_buf, next);
	return (1);
}

// parameter .. check ... need...
int parse_line(t_cub3d *info, char *line, int visited[])
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
			return error_occur(ERROR_BUF_MALLOC);
		visited[id] = 1;
	}
	return (parse_map(info, ft_strdup(line)));
}

int parse_file(t_cub3d *info, const char *path)
{
	int c_fd;
	char *line;
	int r;
	int visited[IDENTIFIERS];

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
		return error_occur(ERROR_MAP_FORMAT_NSEW);
	free(line);
	close(c_fd);
	return (1);
}

void raycasting_start(t_cub3d *info)
{

	// to_string(info);
	
	info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "cub3d");
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
}

int main(int argc, const char *argv[])
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
		// save 옵션 저장 해주기.
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