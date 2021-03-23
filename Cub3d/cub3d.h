/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/23 19:58:01 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "key.h"
# include "error.h"
# include "defines.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_draw
{
	double wall_x;
	double step;
	double tex_pos;
	int draw_s;
	int draw_e;
	int line_h;
	int texture_num;
} t_draw;

typedef struct s_double_pair
{
	double x;
	double y;
} t_d_pair;

typedef struct s_int_pair
{
	int x;
	int y;
} t_i_pair;

typedef struct s_ray
{
	double camera_x;
	double perp_wall_dist;
	t_d_pair dir;
	t_d_pair side_dist;
	t_d_pair delta_dist;
	t_i_pair map;
	t_i_pair step;
	int hit;
	int side;
} t_ray;

typedef struct s_img
{
	void *img;
	int *data;
	int size_l;
	int bpp;
	int endian;
	int img_width;
	int img_height;
} t_img;

typedef struct s_player
{
	t_d_pair pos;
	t_d_pair dir;
	t_d_pair plane;
	t_draw draw;
	double move_speed;
	double rot_speed;
	char point;
} t_player;

typedef struct	s_tex
{
	int			*texture;
	int			width;
	int			height;
}				t_tex;

typedef struct	s_per_sprite
{
	double	x;
	double	y;
	double	dist;
}				t_per_sprite;

typedef struct	s_sprite
{
	t_per_sprite	**info;
	int				cnt;
	double			*z_buffer;
}				t_sprite;

typedef	struct	s_floor
{
	t_d_pair	floor_w;	
	t_d_pair	current_f;
	t_i_pair	tex_f;
	t_tex		texture_f;
	t_tex 		texture_c;
	double		dist_p;
	double		dist_curr;
	double		weight;
}				t_floor;

typedef struct	s_sprite_fill
{
		t_d_pair	spr;
		t_d_pair	transform;
		t_i_pair	tex;
		double		inv_det;
		int 		screen_x;
		int 		v_move_screen;
		int 		sprite_w;
		int 		sprite_h;
		int 		draw_start_y;
		int 		draw_end_y;
		int 		draw_start_x;
		int 		draw_end_x;
}				t_sprite_fill;

typedef struct s_cub3d
{
	void *mlx;
	void *win;
	int **buf;
	int **world_map;
	t_tex texture[IDENTIFIERS];
	int win_width;
	int win_height;
	int map_width;
	int map_height;
	int	save;
	t_img img;
	t_player player;
	t_list *map_buf;
	t_sprite sprites;
}   t_cub3d;

int	main_loop(t_cub3d *info);
int	key_press(int key, t_cub3d *info);
void to_string(t_cub3d *info);

int error_occur(const char *error_message);

/* ray.c */
void	shoot_ray(t_ray *ray, t_cub3d *info, int x);
void	fill_data(t_ray *ray, t_draw *draw, t_cub3d *info, int x);
void	fill_wall(t_ray *ray, t_cub3d *info, t_draw *draw, int x);
void	fill_floor(t_ray *ray, t_cub3d *info, t_draw *draw, int x);
void	fill_sprite(t_cub3d *info, t_sprite *sprites);

int		game_info_init(t_cub3d *info, t_sprite *sprites);

/* list */
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
int		fill_texture(t_tex *tex, int *data, int is_f_c);
int		get_int_value(const char *line, int *i);

int extension_check(const char *path, const char *extension);
int check_identifier(char *line);
int	map_line_check(t_cub3d *info, char *c, int width);
int		load_image(t_cub3d *info, t_tex *tex, char *path, t_img *img);
void	to_string(t_cub3d *info);
int		save_bmp(t_cub3d *info);


#endif
