#include "cub3d.h"

// first => 거리
// second => texture 식별자 ?
// 바꿔야함 win_width로 
// distance 기준으로 내림차순 정렬
void	sort_sprite_desc(t_d_pair **sprite, double *dist, int amount)
{
	double temp;
	t_d_pair *temp_p;

	temp = 0.0;
	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = i + 1; j < amount; j++)
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
		}
	}
}

void	fill_sprite(t_cub3d *info, t_sprite *sprites)
{
	t_player	*p = &info->player;
	t_d_pair	**sprite;
	double		*distance;

	// last free distance ! 해주기 
	if (!(distance = (double *)malloc(sizeof(double) * sprites->cnt)))
	{
		error_occur(ERROR_DISTANCE_MALLOC);
		exit(1);
	}
	sprite = sprites->pos;
	//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < sprites->cnt; i++)
		distance[i] = ((p->pos.x - sprite[i]->x) * (p->pos.x - sprite[i]->x) + (p->pos.y - sprite[i]->y) * (p->pos.y - sprite[i]->y));
	sort_sprite_desc(sprite, distance, sprites->cnt);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < sprites->cnt; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = sprite[i]->x - p->pos.x;
		double spriteY = sprite[i]->y - p->pos.y;

		double invDet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y); //required for correct matrix multiplication

		double transformX = invDet * (p->dir.y * spriteX - p->dir.x * spriteY);
		double transformY = invDet * (-p->plane.y * spriteX + p->plane.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((info->win_width / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((info->win_height / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->win_height / 2 + vMoveScreen;
		if(drawEndY >= info->win_height) drawEndY = info->win_height - 1;
		// printf("drawStartY : %d, drawEndY : %d\n", drawStartY, drawEndY);


		//calculate width of the sprite
		int spriteWidth = (int)fabs((info->win_height / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= info->win_width) drawEndX = info->win_width - 1;

		// printf("drawStartX : %d, drawEndX : %d\n", drawStartX, drawEndX);

		t_tex tex = info->texture[SPRITE];
		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * tex.width / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			// printf("transformY : %f, zBuffer[stripe] : %f\n", transformY, zBuffer[stripe]);
			if(transformY > 0 && stripe > 0 && stripe < info->win_width && transformY < sprites->z_buffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - info->win_height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * tex.height) / spriteHeight) / 256;
				int color = tex.texture[tex.width * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
	free(distance);
}