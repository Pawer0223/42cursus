/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:40:50 by taesan            #+#    #+#             */
/*   Updated: 2021/03/12 17:03:48 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "key.h"
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17

#define ERROR_PARAM "Parameter Error"
#define ERROR_EXTENSION "File Extension Error"
#define ERROR_FILE_PARSE ".cub Parse Error Constant IDENTIFIERS is Duplicated"
#define ERROR_FILE_NOT_EXIST "File Not Exist"
#define ERROR_TEXTURE_LOAD "Texture File Load Error"
#define ERROR_TEXTURE_MALLOC "Texture Malloc Error"
#define ERROR_RGB_FORMAT "Identifier RGB Format Error"
#define ERROR_RGB_VALUE "RGB value Error"
#define ERROR_DEFAULT_INIT "Default Init Error"
#define ERROR_POINT_DUPLICATE "Point(N, S, E, W) Duplicate"
#define ERROR_MAP_MALLOC "WorldMap Malloc Error"
#define ERROR_MAP_FORMAT "WorldMap Format Error"
#define ERROR_BUF_MALLOC "Buf Malloc Error"
#define	ERROR_MAP_FORMAT_NSEW "Map Not Exist N or S or E or W"
#define	ERROR_PARSE_FILE "Parse File Error"
#define ERROR_MAP_LINE_FORMAT "WorldMap Line Format Error"
#define	ERROR_MAP_BUF_MALLOC "Map Buf Malloc Error"
#define	ERROR_FILL_TEXTURE "Texture Info Load Error"
#define	ERROR_SPRITES_MALLOC "Sprites Malloc Error"
#define	ERROR_ADD_SPRITE "Sprites Add Error"
#define ERROR_DISTANCE_MALLOC "Sprite Distance Pointer Malloc Error"

// #define TEX_WIDTH 64
// #define TEX_HEIGHT 64

#define IDENTIFIERS 9
#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3
#define SPRITE 4
#define FLOOR 5
#define CEILING 6
#define RESOLUTION 7
#define MAP_LINE 8

#define MAP_EMPTY_PASS 9


#define MAX_X 1920
#define MAX_Y 1080


// compile => gcc get_next_line.c get_next_line_utils.c main.c -L../libft -lft
// compile => gcc -g get_next_line.c get_next_line_utils.c main.c -L../libft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit

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

typedef struct	s_sprite
{
	t_d_pair	**pos;
	int			cnt;
	double		*z_buffer;

}				t_sprite;

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
