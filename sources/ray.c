#include "../includes/cub3d.h"

void init_dda(t_info *info, t_calc *calc)
{
	if (calc->rayDirX < 0)
	{
		calc->stepX = -1;
		calc->sideDistX = (info->ray.posX - calc->mapX) * calc->deltaDistX;
	}
	else
	{
		calc->stepX = 1;
		calc->sideDistX = (calc->mapX + 1.0 - info->ray.posX) * calc->deltaDistX;
	}
	if (calc->rayDirY < 0)
	{
		calc->stepY = -1;
		calc->sideDistY = (info->ray.posY - calc->mapY) * calc->deltaDistY;
	}
	else
	{
		calc->stepY = 1;
		calc->sideDistY = (calc->mapY + 1.0 - info->ray.posY) * calc->deltaDistY;
	}
}

void perform_dda(t_info *info, t_calc *calc)
{
	while (calc->hit == 0)
	{
		if (calc->sideDistX < calc->sideDistY)
		{
			calc->sideDistX += calc->deltaDistX;
			calc->mapX += calc->stepX;
			calc->side = 0;
		}
		else
		{
			calc->sideDistY += calc->deltaDistY;
			calc->mapY += calc->stepY;
			calc->side = 1;
		}
		if (testMap[calc->mapX][calc->mapY] > 0)
			calc->hit = 1;
	}
	if (calc->side == 0)
		calc->perpWallDist = (calc->mapX - info->ray.posX + (1 - calc->stepX) / 2) / calc->rayDirX;
	else
		calc->perpWallDist = (calc->mapY - info->ray.posY + (1 - calc->stepY) / 2) / calc->rayDirY;
}

void start_ray(int x, t_info *info, t_calc *calc)
{
	calc->cameraX = 2 * x / (double)screenWidth - 1;
	calc->rayDirX = info->ray.dirX + info->ray.planeX * calc->cameraX;
	calc->rayDirY = info->ray.dirY + info->ray.planeY * calc->cameraX;
	calc->mapX = (int)info->ray.posX;
	calc->mapY = (int)info->ray.posY;
	// calc->deltaDistX = fabs(1 / calc->rayDirX);
	// calc->deltaDistY = fabs(1 / calc->rayDirY);
	calc->deltaDistX = sqrt(1 + (calc->rayDirY * calc->rayDirY) / (calc->rayDirX * calc->rayDirX));
	calc->deltaDistY = sqrt(1 + (calc->rayDirX * calc->rayDirX) / (calc->rayDirY * calc->rayDirY));
	calc->hit = 0;
}
