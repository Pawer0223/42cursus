/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/02/26 14:54:03 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ERROR_PARAM			"Parameter Error"
# define ERROR_EXTENSION		"File Extension Error"
# define ERROR_FILE_PARSE		".cub Parse Error Constant IDENTIFIERS is Duplicated"
# define ERROR_FILE_NOT_EXIST 	"File Not Exist"
# define ERROR_TEXTURE_LOAD		"Texture File Load Error"
# define ERROR_TEXTURE_MALLOC 	"Texture Malloc Error"
# define ERROR_RGB_FORMAT		"Identifier R Format Error"
# define ERROR_RGB_VALUE		"RGB value Error"
# define ERROR_DEFAULT_INIT		"Default Init Error"
# define ERROR_POINT_DUPLICATE	"Point(N, S, E, W) Duplicate"
# define ERROR_MAP_MALLOC 		"WorldMap Malloc Error"
# define ERROR_MAP_FORMAT		"WorldMap Format Error"


# define TEX_WIDTH			64
# define TEX_HEIGHT			64

# define IDENTIFIERS	9
# define NORTH			0
# define SOUTH			1
# define WEST			2
# define EAST			3
# define SPRITE			4
# define CEILING		5
# define FLOOR			6
# define RESOLUTION		7
# define MAP_LINE		8

# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx/mlx.h"

// compile => gcc get_next_line.c get_next_line_utils.c main.c -L../libft -lft
// compile => gcc -g get_next_line.c get_next_line_utils.c main.c -L../libft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit

typedef struct	s_draw
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		draw_s;
	int		draw_e;
	int		line_h;
	int		texture_num;
}				t_draw;

typedef struct  s_double_pair
{
    double      x;
    double      y;
}               t_d_pair;

typedef struct  s_int_pair
{
    int	x;
	int	y;
}               t_i_pair;

typedef struct	s_ray
{
	double		camera_x;
	double		perp_wall_dist;
	t_d_pair	dir;
	t_d_pair	side_dist;
	t_d_pair	delta_dist;
	t_i_pair	map;
	t_i_pair	step;
	int			hit;
	int			side;
}				t_ray;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_player
{
    // void		*mlx;
	// void		*win;
    t_d_pair 	pos;
    t_d_pair 	dir;
    t_d_pair 	plane;
	// t_img		img;
	t_draw		draw;
	// int		buf[height][width];
	// int			**texture;
	double		move_speed;
	double		rot_sppeed;
	char		point;
}				t_player;


typedef struct	s_cub3d
{   
	void		*mlx;
	void		*win;
	int			**buf;
	int			**world_map;
	// int			buf[height][width];
	int			*texture[IDENTIFIERS];
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	t_img		img;
	t_player	player;
	t_list		*map_buf;
}				t_cub3d;

int	error_occur(const char *error_message)
{
	printf("Error\n");
	printf(": [%s]\n", error_message);
    return (0);
}

int			default_init(t_cub3d *info)
{
	int i;
	int	j;
	
	ft_bzero(info, sizeof(t_cub3d));
	info->mlx = mlx_init();
	i = 0;
	while (i < IDENTIFIERS)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
		{
			j = 0;
			while (j < i)
				free(info->texture[j++]);
			return error_occur(ERROR_TEXTURE_MALLOC);
		}
		ft_bzero(info->texture[i], TEX_HEIGHT * TEX_WIDTH);
		i++;
	}
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

int     extension_check(const char *path, const char *extension)
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

int		get_int_value(const char *line, int *i)
{
	int	value;

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

int		parse_id_r(t_cub3d *info, char *line)
{
	int		i;
	
	i = 1;
	info->win_width = get_int_value(line , &i);
	info->win_height = get_int_value(line, &i);
	if (info->win_width == -1 || info->win_height == -1)
		return (0);
	i = 0;
	return (1);
}


int		load_image(t_cub3d *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian)))
		return (0);
	x = 0;
	y = 0;
	while (y < img->img_height)
	{
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int		parse_and_load_texture(t_cub3d *info, int id, char *line)
{
	int		i;
	t_img	img;

	i = (id == SPRITE) ? 2 : 3;
	if (!load_image(info, info->texture[id], (line + i), &img))
		return (error_occur(ERROR_TEXTURE_LOAD));
	return (1);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);	
}

int		is_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) || line[i] != ' ' || line[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

int		set_color(int *color, int *value, int seq)
{
	if (*value < 0 || *value > 255)
		return (error_occur(ERROR_RGB_VALUE));
	*color = *color | (*value << (16 - (seq * 8)));
	*value = 0;
	return (1);
}

int		parse_color(t_cub3d *info, int id, char *line)
{
	int	i;
	int	value;
	int	seq;

	i = 2;
	value = 0;
	seq = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			value = value * 10 + line[i] - '0';
		else if (line[i] == ',')
		{
			if(!set_color(info->texture[id], &value, seq++))
				return (0);
		}
		else
			return ((error_occur(ERROR_RGB_FORMAT)));
		i++;
	}
	if (i == 2 || seq != 2 || !set_color(info->texture[id], &value, seq))
		return ((error_occur(ERROR_RGB_FORMAT)));
	return (1);
}

int		map_line_check(t_cub3d *info, char c, int width)
{
	if ((c >= '0' && c <= '4') || c == ' ')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (info->player.point)
			return error_occur(ERROR_POINT_DUPLICATE);
		info->player.point = c;
		info->player.pos.x = width;
		info->player.pos.y = info->map_height;
		return (2);
	}
	else
		return (0);
}

int		ft_max(int a, int b)
{
	return (a > b) ? a : b;
}

void	del_line(void *line)
{
	free(line);
}

int		parse_map(t_cub3d *info, char *line)
{
	// 1, 2, 3, 4 N,S,E,W 만 가능하도록
	int 	i;
	int		r;
	int		width;
	t_list	*next;

	i = 0;
	width = 0;
	r = 0;
	while (line[i])
	{
		if (!(r = map_line_check(info, line[i], width)))
			return (0);
		if (r == 2)
			line[i] = '0';
		width++;
		i++;
	}
	info->map_width = ft_max(info->map_width, width);
	info->map_height++;
	if (!(next = ft_lstnew(line)))
	{
		ft_lstclear(&info->map_buf, &del_line);
		return (0);
	}
	ft_lstadd_back(&info->map_buf, next);
	return (1);
}

// parameter .. check ... need...
int    parse_line(t_cub3d *info, char *line, int visited[])   
{
    int		id;

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
			return (0);
		visited[id] = 1;
	}
	return (parse_map(info, ft_strdup(line)));
}

int		parse_file(t_cub3d *info, const char *path)
{
	int			c_fd;
	char		*line;
	int			r;
	int 		visited[IDENTIFIERS];

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
	if (!r || parse_line(info, line, visited))
		return (0);
	free(line);
	close(c_fd);
	return (1);
}

void	print_list(void *content)
{
	printf("[%s]\n", content);
}

void	to_string(t_cub3d *info)
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
	printf("move_speed : %f, rot_speed : %f\n", info->player.move_speed ,info->player.move_speed);
}

int		world_map_malloc(int **map, int width, int i)
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

void	print_world_map(t_cub3d *info)
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


int		make_world_map(t_cub3d *info)
{
	int 	**map;
	int		i;
	int		j;
	t_list	*curr;

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
		i++;
		curr = curr->next;
	}
	info->world_map = map;
	return (1);
}

int	map_valid_check(t_cub3d *info)
{
	// 0 주변에는 1만 존재해야 함.
	
	return (1);
}

int	main(int argc, const char *argv[])
{
	t_cub3d info;

	if (!default_init(&info))
		return error_occur(ERROR_DEFAULT_INIT);
	if (argc == 2)
        parse_file(&info, argv[1]);
    else if (argc == 3)
    {
		if (ft_strcmp(argv[1], "--save") != 0)
			return (error_occur(ERROR_PARAM));
        // save 옵션 저장 해주기.
        parse_file(&info, argv[2]);
	}
    else
        return (error_occur(ERROR_PARAM));
	if (!make_world_map(&info))
		return (error_occur(ERROR_MAP_MALLOC));
	ft_lstclear(&info.map_buf, &del_line);
	if (!map_valid_check(&info))
		return error_occur(ERROR_MAP_FORMAT);
	to_string(&info);
}