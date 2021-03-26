/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/26 19:44:59 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
	**libs
*/
# include "mlx/mlx.h"
# include "libft/libft.h"

# include "key.h"
# include "error.h"
# include "defines.h"
# include "structs.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		main_loop(t_cub3d *info);
int		key_press(int key, t_cub3d *info);
void	to_string(t_cub3d *info);
int		error_occur(const char *error_message);

void	shoot_ray(t_ray *ray, t_cub3d *info, int x);
void	fill_data(t_ray *ray, t_draw *draw, t_cub3d *info, int x);
void	fill_wall(t_ray *ray, t_cub3d *info, t_draw *draw, int x);
void	fill_floor(t_ray *ray, t_cub3d *info, t_draw *draw, int x);
void	fill_sprite(t_cub3d *info, t_sprite *sprites);

int		game_info_init(t_cub3d *info, t_sprite *sprites);

void	del_line(void *line);

int		make_world_map(int **map, int width, t_list *curr, t_per_sprite **ss);
int		edge_left_right_check(t_cub3d *info, int limit);
int		edge_up_down_check(t_cub3d *info, int limit);

int		get_next_line(int fd, char **line);
int		ft_max(int a, int b);
int		ft_isspace(char c);
int		is_empty_line(char *line);
char	*content_null(char *buf);
int		error_occur(const char *error_message);
int		parse_file(t_cub3d *info, const char *path);
int		parse_color(t_cub3d *info, int id, char *line);
int		parse_and_load_texture(t_cub3d *info, int id, char *line);
int		fill_texture(t_tex *tex, int *data, int is_f_c);
int		get_int_value(const char *line, int *i);

int		extension_check(const char *path, const char *extension);
int		map_valid_check(t_cub3d *info);
int		check_identifier(char *line);
int		map_line_check(t_cub3d *info, char *c, int width);
int		load_image(t_cub3d *info, t_tex *tex, char *path, t_img *img);
void	to_string(t_cub3d *info);
int		save_bmp(t_cub3d *info);
void	raycasting(t_cub3d *info);
void	exit_game(t_cub3d *info);


#endif
