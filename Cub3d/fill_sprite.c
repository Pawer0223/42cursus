#include "cub3d.h"

// first => 거리
// second => texture 식별자 ?
// 바꿔야함 win_width로 
// distance 기준으로 내림차순 정렬
void	sort_sprite_desc(t_d_pair **sprite, double *dist, int amount)
{
	t_d_pair	*temp_p;
	double		temp;
	int			i;
	int			j;

	temp = 0.0;
	i = 0;
	while (i < amount - 1)
	{
		j = i + 1;
		while (j < amount)
		{
			if (dist[i] < dist[j])
			{
				temp = dist[i];
				temp_p = sprite[i];				
				dist[i] = dist[j];
				sprite[i] = sprite[j];			
				dist[j] = temp;
				sprite[j] = temp_p;
			}
			j++;
		}
		i++;
	}
}

void temp(t_cub3d *info, t_sprite *sprites,	t_player p)
{
	t_d_pair	**sprite;

	sprite = sprites->pos;
	for (int i = 0; i < sprites->cnt; i++)
	{
		double spriteX = sprite[i]->x - p.pos.x;
		double spriteY = sprite[i]->y - p.pos.y;

		double invDet = 1.0 / (p.plane.x * p.dir.y - p.dir.x * p.plane.y);
		double transformX = invDet * (p.dir.y * spriteX - p.dir.x * spriteY);
		double transformY = invDet * (-p.plane.y * spriteX + p.plane.x * spriteY);

		int spriteScreenX = (int)((info->win_width / 2) * (1 + transformX / transformY));
		int vMoveScreen = (int)(V_MOVE / transformY);
		int spriteHeight = (int)fabs((info->win_height / transformY) / V_DIV);
		int drawStartY = -spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if (drawEndY >= info->win_height)
			drawEndY = info->win_height - 1;

		int spriteWidth = (int)fabs((info->win_height / transformY) / U_DIV);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= info->win_width)
			drawEndX = info->win_width - 1;

		t_tex tex = info->texture[SPRITE];
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * tex.width / spriteWidth) / 256);
			if (transformY > 0 && stripe > 0 && stripe < info->win_width && transformY < sprites->z_buffer[stripe])
				for (int y = drawStartY; y < drawEndY; y++)
				{
					int d = (y - vMoveScreen) * 256 - info->win_height * 128 + spriteHeight * 128;
					int texY = ((d * tex.height) / spriteHeight) / 256;
					int color = tex.texture[tex.width * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						info->buf[y][stripe] = color;
				}
		}
	}
}

void	fill_sprite(t_cub3d *info, t_sprite *sprites)
{
	t_d_pair	**sprite;
	double		*distance;
	t_player	p;
	p = info->player;

	if (!(distance = (double *)malloc(sizeof(double) * sprites->cnt)))
	{
		error_occur(ERROR_DISTANCE_MALLOC);
		exit(1);
	}
	sprite = sprites->pos;
	for (int i = 0; i < sprites->cnt; i++)
		distance[i] = ((p.pos.x - sprite[i]->x) * (p.pos.x - sprite[i]->x) + (p.pos.y - sprite[i]->y) * (p.pos.y - sprite[i]->y));
	sort_sprite_desc(sprite, distance, sprites->cnt);
	temp(info, sprites, info->player);
	free(distance);
}