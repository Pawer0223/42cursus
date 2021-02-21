/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/02/22 02:25:06 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define C_R				0
# define C_NO				1
# define C_SO				2
# define C_WE				3
# define C_EA				4
# define C_S				5
# define C_F				6
# define C_C				7
# define C_MAP				8
# define C_SIZE 			9

# define ERROR_PARAM        "Parameter Error"
# define ERROR_EXTENSION    "File Extension Error"


# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "get_next_line.h"

// typedef struct	s_draw
// {
// 	double	wall_x;
// 	double	step;
// 	double	tex_pos;
// 	int		draw_s;
// 	int		draw_e;
// 	int		line_h;
// 	int		texture_num;
// }				t_draw;

// typedef struct  s_double_pair
// {
//     double      x;
//     double      y;
// }               t_d_pair;

// typedef struct  s_int_pair
// {
//     int	x;
// 	int	y;
// }               t_i_pair;

// typedef struct	s_ray
// {
// 	double		camera_x;
// 	double		perp_wall_dist;
// 	t_d_pair	dir;
// 	t_d_pair	side_dist;
// 	t_d_pair	delta_dist;
// 	t_i_pair	map;
// 	t_i_pair	step;
// 	int			hit;
// 	int			side;
// }				t_ray;

// typedef struct	s_img
// {
// 	void	*img;
// 	int		*data;
// 	int		size_l;
// 	int		bpp;
// 	int		endian;
// 	int		img_width;
// 	int		img_height;
// }				t_img;

// typedef struct	s_player
// {
//     // void		*mlx;
// 	// void		*win;
//     t_d_pair 	pos;
//     t_d_pair 	dir;
//     t_d_pair 	plane;
// 	// t_img		img;
// 	t_draw		draw;
// 	// int		buf[height][width];
// 	// int			**texture;
// 	double		move_speed;
// 	double		rot_sppeed;
// }				t_player;


// typedef struct	s_cub3d
// {   
// 	void		*mlx;
// 	void		*win;
// 	int			**buf;
// 	int			**world_map;
// 	// int			buf[height][width];
// 	int			*texture[];
// 	t_img		img;
// 	t_player	player;
// }				t_cub3d;

int check_identifier(char const *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (C_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (C_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (C_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (C_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (C_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (C_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (C_F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C_C);
	return (C_MAP);
}

// compile => gcc get_next_line.c get_next_line_utils.c main.c -L../libft -lft
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

int    parse_line(char *line)
{
    int map_id;

    map_id = check_identifier(line);
    // printf("line : %s, id : %d\n", line, map_id);

    // 	if (map_id == C_R)
	// 	return (parse_dimensions(config, line));
	// else if (map_id >= C_NO && map_id <= C_S)
	// 	return (parse_texture(config, key, line));
	// else if (map_id == C_F || map_id == C_C)
	// 	return (parse_color(config, key, line));
	// config->set[key] = 1;
	// if (empty_in_map)
	// 	content_after = 1;
	// return (!!str_add_back(map_buffer, ft_strdup(line)));

    return (0);
}

int parse_file(const char *path)
{
	int			c_fd;
	char		*line;
	int			r;

	if (!extension_check(path, ".cub"))
        return (error_occur(ERROR_EXTENSION));
	if ((c_fd = open(path, O_RDONLY)) < 0)
		return (0);
	r = 1;
	while (get_next_line(c_fd, &line))
	{
        parse_line(line);
		free(line);
	}
    printf("%s\n", line);
	free(line);
	close(c_fd);
	return (1);
}

int	main2(int argc, const char *argv[])
{
	if (argc == 2)
        parse_file(argv[1]);
    else if (argc == 3)
    {
		if (ft_strcmp(argv[1], "--save") != 0)
			return (error_occur(ERROR_PARAM));
        // save 옵션 저장 해주기.
        parse_file(argv[2]);
	}
    else
        return (error_occur(ERROR_PARAM));
}