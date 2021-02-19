#include "mlx/mlx.h"
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

typedef struct  s_pair
{
    double      x;
    double      y;
}               t_pair;

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

typedef struct	s_info
{
    void	*mlx;
	void	*win;
    t_pair  pos;
    t_pair  dir;
    t_pair  plane;
	t_img	img;
	int		buf[height][width];
	int		**texture;
    int     *map;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

void	calc(t_info *info);