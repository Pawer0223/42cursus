/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/04 18:52:57 by taekang          ###   ########.fr       */
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

void to_string(t_cub3d *info)
{
	printf("win_width : %d\n", info->win_width);
	printf("win_height : %d\n", info->win_height);
	printf("map_width : %d\n", info->map_width);
	printf("map_height : %d\n", info->map_height);
	printf("### map_buf ###\n");
	ft_lstiter(info->map_buf, &print_list);
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

/*
	init
*/
int default_init(t_cub3d *info)
{
	int i;
	// int j;

	ft_bzero(info, sizeof(t_cub3d));
	info->mlx = mlx_init();
	i = 0;
	while (i < IDENTIFIERS)
	{
		ft_bzero(&info->texture[i], sizeof(t_tex));
		i++;
	}

	// while (i < IDENTIFIERS)
	// {
	// 	if (!(info->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
	// 	{
	// 		j = 0;
	// 		while (j < i)
	// 			free(info->texture[j++]);
	// 		return error_occur(ERROR_TEXTURE_MALLOC);
	// 	}
	// 	ft_bzero(info->texture[i], sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	// 	i++;
	// }
	return (1);
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

int load_image(t_cub3d *info, t_tex *tex, char *path, t_img *img)
{
	int x;
	int y;

	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &tex->width, &tex->height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian)))
		return (0);
	if (!(tex->texture = (int *)malloc(sizeof(int) * tex->width * tex->height)))
		return (0);
	ft_bzero(tex->texture, tex->width * tex->height * sizeof(int));
	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			tex->texture[tex->width * y + x] = img->data[tex->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int parse_and_load_texture(t_cub3d *info, int id, char *line)
{
	int i;
	t_img img;

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

int set_color(t_tex *tex, int *value, int seq)
{
	if (!tex->texture)
	{
		if (!(tex->texture = (int *)malloc(sizeof(int))))
			return error_occur(ERROR_TEXTURE_MALLOC);
		tex->height = 64;
		tex->width = 64;
	}
	if (*value < 0 || *value > 255)
		return (error_occur(ERROR_RGB_VALUE));
	*tex->texture = *tex->texture | (*value << (16 - (seq * 8)));
	*value = 0;
	return (1);
}

int parse_color(t_cub3d *info, int id, char *line)
{
	int i;
	int value;
	int seq;

	i = 2;
	value = 0;
	seq = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			value = value * 10 + line[i] - '0';
		else if (line[i] == ',')
		{
			if (!set_color(&info->texture[id], &value, seq++))
				return (0);
		}
		else
			return ((error_occur(ERROR_RGB_FORMAT)));
		i++;
	}
	if (i == 2 || seq != 2 || !set_color(&info->texture[id], &value, seq))
		return ((error_occur(ERROR_RGB_FORMAT)));
	return (1);
}

int	map_line_check(t_cub3d *info, char c, int width)
{
	if ((c >= '0' && c <= '4') || c == ' ')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (info->player.point)
			return error_occur(ERROR_POINT_DUPLICATE);
		info->player.point = c;
		info->player.pos.x = info->map_height + 0.5;
		info->player.pos.y = width + 0.5;
		return (2);
	}
	else
		return error_occur(ERROR_MAP_LINE_FORMAT);
}

int ft_max(int a, int b)
{
	return (a > b) ? a : b;
}

void del_line(void *line)
{
	free(line);
}

int parse_map(t_cub3d *info, char *line)
{
	// 1, 2, 3, 4 N,S,E,W 만 가능하도록
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

int world_map_malloc(int **map, int width, int i)
{
	int j;

	if (!(map[i] = (int *)malloc(sizeof(int) * width)))
	{
		j = 0;
		while (j < i)
			free(map[j++]);
		return (0);
	}
	return (1);
}

int make_world_map(t_cub3d *info)
{
	int **map;
	int i;
	int j;
	t_list *curr;

	if (!(map = (int **)malloc(sizeof(int *) * info->map_height)))
		return (0);
	i = 0;
	curr = info->map_buf;
	while (curr)
	{
		if (!world_map_malloc(map, info->map_width, i))
			return (0);
		j = 0;
		while (*(char *)(curr->content + j))
		{
			map[i][j] = *(char *)(curr->content + j) - '0';
			j++;
		}
		while (j < info->map_width)
			map[i][j++] = MAP_EMPTY_PASS;
		i++;
		curr = curr->next;
	}
	info->world_map = map;
	return (1);
}

int edge_left_right_check(t_cub3d *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (info->world_map[i][j] && info->world_map[i][j] == MAP_EMPTY_PASS)
			j++;
		if (info->world_map[i][j] == 0)
			return (0);
		j = info->map_width - 1;
		while (j >= 0 && info->world_map[i][j] == MAP_EMPTY_PASS)
			j--;
		if (info->world_map[i][j] == 0)
			return (0);
		i++;
	}
	return (1);
}

int edge_up_down_check(t_cub3d *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_width)
	{
		j = 0;
		while (info->world_map[j][i] && info->world_map[j][i] == MAP_EMPTY_PASS)
			j++;
		if (info->world_map[j][i] == 0)
			return (0);
		j = info->map_height - 1;
		while (j >= 0 && info->world_map[j][i] == MAP_EMPTY_PASS)
			j--;
		if (info->world_map[j][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	player_init(t_player *p)
{
	p->dir.x = -1.0;
	p->dir.y = 0.0;
	p->plane.x = 0.0;
	p->plane.y = 0.66;
	p->move_speed = 0.05;
	p->rot_sppeed = 0.05;
}

int cub3d_init(t_cub3d *info)
{
	int i;
	int	j;

	if (!(info->buf = (int **)malloc(sizeof(int *) * info->win_height)))
		return error_occur(ERROR_BUF_MALLOC);
	i = 0;
	while (i < info->win_height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * info->win_width)))
		{
			j = 0;
			while (j < i)
				free(info->buf[j++]);
			return error_occur(ERROR_BUF_MALLOC);
		}
		i++;
	}
	return (1);
}

int raycasting_start(t_cub3d *info)
{
	int max_x;
	int max_y;
	int	i;
	
	to_string(info);
	// mlx_get_screen_size(info->mlx, &max_x, &max_y);
	max_x = 1920;
	max_y = 1080;
	printf("max_x : %d, max_y : %d\n", max_x , max_y);
	if (info->win_height > max_x)
		info->win_height = max_x;
	if (info->win_width > max_y)
		info->win_width = max_y;
	player_init(&info->player);
	if (!cub3d_init(info))
		return (0);
	info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "cub3d");
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
	return (1);
}

int main(int argc, const char *argv[])
{
	t_cub3d info;
	int		r;
	
	if (!default_init(&info))
		return error_occur(ERROR_DEFAULT_INIT);
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
		return error_occur(ERROR_PARSE_FILE);
	if (!make_world_map(&info))
		return (error_occur(ERROR_MAP_MALLOC));
	ft_lstclear(&info.map_buf, &del_line);
	if (!edge_left_right_check(&info) || !edge_up_down_check(&info))
	{
		//map free
		return error_occur(ERROR_MAP_FORMAT);
	}
	raycasting_start(&info);
}