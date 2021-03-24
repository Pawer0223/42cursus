/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:46:12 by taekang           #+#    #+#             */
/*   Updated: 2021/03/24 14:56:22 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_draw
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		draw_s;
	int		draw_e;
	int		line_h;
	int		texture_num;
}					t_draw;

typedef struct		s_double_pair
{
	double	x;
	double	y;
}					t_d_pair;

typedef struct		s_int_pair
{
	int x;
	int y;
}					t_i_pair;

typedef struct		s_ray
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
}					t_ray;

typedef struct		s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}					t_img;

typedef struct		s_player
{
	t_d_pair	pos;
	t_d_pair	dir;
	t_d_pair	plane;
	t_draw		draw;
	double		move_speed;
	double		rot_speed;
	char		point;
}					t_player;

typedef struct		s_tex
{
	int			*texture;
	int			width;
	int			height;
}					t_tex;

typedef struct		s_per_sprite
{
	double	x;
	double	y;
	double	dist;
}					t_per_sprite;

typedef struct		s_sprite
{
	t_per_sprite	**info;
	double			*z_buffer;
	int				cnt;
}					t_sprite;

typedef	struct		s_floor
{
	t_d_pair	floor_w;
	t_d_pair	current_f;
	t_i_pair	tex_f;
	t_tex		texture_f;
	t_tex		texture_c;
	double		dist_p;
	double		dist_curr;
	double		weight;
}					t_floor;

typedef struct		s_sprite_fill
{
	t_d_pair	spr;
	t_d_pair	transform;
	t_i_pair	tex;
	double		inv_det;
	int			screen_x;
	int			v_move_screen;
	int			sprite_w;
	int			sprite_h;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
}					t_sprite_fill;

typedef struct		s_cub3d
{
	void		*mlx;
	void		*win;
	int			**buf;
	int			**world_map;
	t_tex		texture[IDENTIFIERS];
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	int			save;
	t_img		img;
	t_player	player;
	t_list		*map_buf;
	t_sprite	sprites;
}					t_cub3d;
#endif
