#include "../mlx/mlx.h"
#include "key.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480

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
	//int			**buf;
	//int			**world_map;
	int			buf[height][width];
	int			**texture;
	t_img		img;
	t_player	player;
}				t_cub3d;

void	calc(t_cub3d *info);