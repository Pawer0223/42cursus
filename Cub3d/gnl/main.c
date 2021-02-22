/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/02/23 02:28:48 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ERROR_PARAM		"Parameter Error"
# define ERROR_EXTENSION	"File Extension Error"
# define ERROR_FILE_PARSE	".cub parse Error constant IDENTIFIERS is duplicated"

# define TEXTURES			8
# define TEX_NORTH			0 // eagle
# define TEX_SOUTH			1 // redbrick
# define TEX_WEST			2 // purplestone
# define TEX_EAST			3 // wall_type_etc1 , mossy
# define TEX_CEILING		4 // celing, wood
# define TEX_FLOOR			5 // floor1, greystone
# define TEX_SPRITE			6 // sprite... , blue stone , not used
# define TEX_SPRITE_UP		7 // colorstone
# define TEX_WIDTH			64
# define TEX_HEIGHT			64

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
}				t_player;


typedef struct	s_cub3d
{   
	void		*mlx;
	void		*win;
	int			**buf;
	int			**world_map;
	// int			buf[height][width];
	int			*texture[TEXTURES];
	int			win_width;
	int			win_height;
	t_img		img;
	t_player	player;
}				t_cub3d;

// void	load_texture(t_cub3d *info)
// {
// 	t_img	img;

// 	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
// 	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
// 	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
// 	load_image(info, info->texture[3], "textures/greystone.xpm", &img);		
// 	load_image(info, info->texture[4], "textures/mossy.xpm", &img);
// 	load_image(info, info->texture[5], "textures/wood.xpm", &img);	
// 	load_image(info, info->texture[6], "textures/bluestone.xpm", &img);
// 	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
// }


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

int check_identifier(char const *line)
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

int	error_occur(const char *error_message)
{
	printf("Error\n");
	printf("[%s]\n", error_message);
    return (0);
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

int		parse_id_r(t_cub3d *info, char const *line)
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


void	load_image2(t_cub3d *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

int		parse_texture(t_cub3d *info, int id, char const *line)
{
	char	*path;
	int		i;
	int		len;

	i = (id == SPRITE) ? 2 : 3;
	len = ft_strlen(line + i);
	if (!(path = ft_substr(line, i, len)))
		return (0);
	printf("path : [%s]\n", line + i);
	load_image2(info, info->texture[id], (char *)(line + i), &info->img);
	return (1);
}

// parameter .. check ... need...
int    parse_line(t_cub3d *info, char *line, int visited[])
{
    int id;

    id = check_identifier(line);
	if (id != MAP_LINE && visited[id])
		return (error_occur(ERROR_FILE_PARSE));
	visited[id] = 1;
    if (id == RESOLUTION)
		return (parse_id_r(info, line));
	else if (id >= NORTH && id <= SPRITE)
		return (parse_texture(info, id, line));
	// else if (id == FLOOR || id == CEILING)
	// 	return (parse_color(config, key, line));
	// return (!!str_add_back(map_buffer, ft_strdup(line)));
    return (0);
}

int			default_init(t_cub3d *info, int visited[])
{
	int i;
	int	j;

	i = 0;
	while (i < TEXTURES)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
		{
			j = 0;
			while (j < i)
				free(info->texture[j++]);
			return (0);
		}
		i++;
	}

	i = 0;
	j = 0;
	while (i < TEXTURES)
	{
		while (j < (TEX_HEIGHT * TEX_WIDTH))
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < IDENTIFIERS)
		visited[i++] = 0;
	return (1);
}

int parse_file(t_cub3d *info, const char *path)
{
	int			c_fd;
	char		*line;
	int			r;
	int 		visited[IDENTIFIERS];

	if (!extension_check(path, ".cub"))
        return (error_occur(ERROR_EXTENSION));
	if ((c_fd = open(path, O_RDONLY)) < 0)
		return (0);
	if (!default_init(info, visited))
		return (0);
	r = 1;
	while (get_next_line(c_fd, &line))
	{
        r = parse_line(info, line, visited);
		free(line);
		if (!r)
			return (0);
	}
	free(line);
	close(c_fd);
	return (1);
}

int	main(int argc, const char *argv[])
{
	t_cub3d info;
	info.mlx = mlx_init();

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
}