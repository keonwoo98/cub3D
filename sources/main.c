#include "../includes/cub3d.h"

/*
0 : 빈 공간
1 : 벽
2 : 내부의 작은 방
3 : 몇 개의 기둥
4 : 복도
*/
int testMap[mapWidth][mapHeight] =
{
	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
	{4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
	{4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
	{4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
	{6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
	{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
	{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}
};

void rotate_vector(t_info *info, double angle)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = info->ray.dirX;
	oldPlaneX = info->ray.planeX;
	info->ray.dirX = info->ray.dirX * cos(angle) - info->ray.dirY * sin(angle);
	info->ray.dirY = oldDirX * sin(angle) + info->ray.dirY * cos(angle);
	info->ray.planeX = info->ray.planeX * cos(angle) - info->ray.planeY * sin(angle);
	info->ray.planeY = oldPlaneX * sin(angle) + info->ray.planeY * cos(angle);
}

int key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (!testMap[(int)(info->ray.posX + info->ray.dirX * info->ray.moveSpeed)][(int)(info->ray.posY)])
			info->ray.posX += info->ray.dirX * info->ray.moveSpeed;
		if (!testMap[(int)(info->ray.posX)][(int)(info->ray.posY + info->ray.dirY * info->ray.moveSpeed)])
			info->ray.posY += info->ray.dirY * info->ray.moveSpeed;
	}
	if (keycode == KEY_S)
	{
		if (!testMap[(int)(info->ray.posX - info->ray.dirX * info->ray.moveSpeed)][(int)(info->ray.posY)])
			info->ray.posX -= info->ray.dirX * info->ray.moveSpeed;
		if (!testMap[(int)(info->ray.posX)][(int)(info->ray.posY - info->ray.dirY * info->ray.moveSpeed)])
			info->ray.posY -= info->ray.dirY * info->ray.moveSpeed;
	}
	if (keycode == KEY_D)
	{
		rotate_vector(info, -info->ray.rotSpeed);
		// double oldDirX = info->ray.dirX;
		// info->ray.dirX = info->ray.dirX * cos(-info->ray.rotSpeed) - info->ray.dirY * sin(-info->ray.rotSpeed);
		// info->ray.dirY = oldDirX * sin(-info->ray.rotSpeed) + info->ray.dirY * cos(-info->ray.rotSpeed);
		// double oldPlaneX = info->ray.planeX;
		// info->ray.planeX = info->ray.planeX * cos(-info->ray.rotSpeed) - info->ray.planeY * sin(-info->ray.rotSpeed);
		// info->ray.planeY = oldPlaneX * sin(-info->ray.rotSpeed) + info->ray.planeY * cos(-info->ray.rotSpeed);
	}
	if (keycode == KEY_A)
	{
		rotate_vector(info, info->ray.rotSpeed);
		// double oldDirX = info->ray.dirX;
		// info->ray.dirX = info->ray.dirX * cos(info->ray.rotSpeed) - info->ray.dirY * sin(info->ray.rotSpeed);
		// info->ray.dirY = oldDirX * sin(info->ray.rotSpeed) + info->ray.dirY * cos(info->ray.rotSpeed);
		// double oldPlaneX = info->ray.planeX;
		// info->ray.planeX = info->ray.planeX * cos(info->ray.rotSpeed) - info->ray.planeY * sin(info->ray.rotSpeed);
		// info->ray.planeY = oldPlaneX * sin(info->ray.rotSpeed) + info->ray.planeY * cos(info->ray.rotSpeed);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void draw(t_info *info)
{
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
			info->img.data[y * screenWidth + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void calc(t_info *info)
{
	int x;

	x = 0;
	while (x < screenWidth)
	{
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = info->ray.dirX + info->ray.planeX * cameraX;
		double rayDirY = info->ray.dirY + info->ray.planeY * cameraX;

		int mapX = (int)info->ray.posX;
		int mapY = (int)info->ray.posY;

		double sideDistX;
		double sideDistY;

		// double deltaDistX = fabs(1 / rayDirX);
		// double deltaDistY = fabs(1 / rayDirY);
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->ray.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->ray.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->ray.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->ray.posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (testMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->ray.posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->ray.posY + (1 - stepY) / 2) / rayDirY;
		
		int lineHeight = (int)(screenHeight / perpWallDist);

		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		
		int texNum = testMap[mapX][mapY];

		double wallX;	// 벽의 int형 좌표가 아닌 double형 좌표로 벽의 정확히 어디에 부딪혔는지를 나타냄
		if (side == 0)
			wallX = info->ray.posY + perpWallDist * rayDirY;
		else
			wallX = info->ray.posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		
		double step = 1.0 * texHeight / lineHeight;

		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texNum][texHeight * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		x++;
	}
}

int main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int main(int argc, char **argv)
{
	t_info info;

	info.mlx = mlx_init();
	init_info(&info);
	if (parsing(argc, argv, &info))
		return (-1);

	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "Cub3D");
	info.img.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.line_size, &info.img.endian);
	mlx_hook(info.win, KEY_EVENT_PRESS, 0, &key_press, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
