#include "../includes/cub3d.h"

void init_wall_texture(t_info *info, t_calc *calc)
{
	calc->lineHeight = (int)(screenHeight / calc->perpWallDist);
	calc->drawStart = -calc->lineHeight / 2 + screenHeight / 2;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	calc->drawEnd = calc->lineHeight / 2 + screenHeight / 2;
	if (calc->drawEnd >= screenHeight)
		calc->drawEnd = screenHeight - 1;
	calc->texNum = testMap[calc->mapX][calc->mapY];
	// calc->wallX;	// 벽의 int형 좌표가 아닌 double형 좌표로 벽의 정확히 어디에 부딪혔는지를 나타냄
	if (calc->side == 0)
		calc->wallX = info->ray.posY + calc->perpWallDist * calc->rayDirY;
	else
		calc->wallX = info->ray.posX + calc->perpWallDist * calc->rayDirX;
	calc->wallX -= floor(calc->wallX);
	calc->texX = (int)(calc->wallX * (double)texWidth);
	if (calc->side == 0 && calc->rayDirX > 0)
		calc->texX = texWidth - calc->texX - 1;
	if (calc->side == 1 && calc->rayDirY < 0)
		calc->texX = texWidth - calc->texX - 1;
}

void input_wall_texture(int x, t_info *info, t_calc *calc)
{
	int y;
	int color;

	calc->step = 1.0 * texHeight / calc->lineHeight;
	calc->texPos = (calc->drawStart - screenHeight / 2 + calc->lineHeight / 2) * calc->step;
	y = -1;
	while (++y < screenHeight)
	{
		if (y >= calc->drawStart && y <= calc->drawEnd)
		{
			calc->texY = (int)calc->texPos & (texHeight - 1);
			calc->texPos += calc->step;
			color = info->texture[calc->texNum][texHeight * calc->texY + calc->texX];
			if (calc->side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		else if (y < calc->drawStart)
			info->buf[y][x] = SKYBLUE;
		else
			info->buf[y][x] = GREY;
	}
}
