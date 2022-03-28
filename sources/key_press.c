#include "../includes/cub3d.h"

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

void player_move(t_info *info)
{
	if (info->key_w)
	{
		if (!testMap[(int)(info->ray.posX + info->ray.dirX * info->ray.moveSpeed)][(int)(info->ray.posY)])
			info->ray.posX += info->ray.dirX * info->ray.moveSpeed;
		if (!testMap[(int)(info->ray.posX)][(int)(info->ray.posY + info->ray.dirY * info->ray.moveSpeed)])
			info->ray.posY += info->ray.dirY * info->ray.moveSpeed;
	}
	if (info->key_s)
	{
		if (!testMap[(int)(info->ray.posX - info->ray.dirX * info->ray.moveSpeed)][(int)(info->ray.posY)])
			info->ray.posX -= info->ray.dirX * info->ray.moveSpeed;
		if (!testMap[(int)(info->ray.posX)][(int)(info->ray.posY - info->ray.dirY * info->ray.moveSpeed)])
			info->ray.posY -= info->ray.dirY * info->ray.moveSpeed;
	}
	if (info->key_d)
		rotate_vector(info, -info->ray.rotSpeed);
	if (info->key_a)
		rotate_vector(info, info->ray.rotSpeed);
}

int key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		info->key_w = 1;
	else if (keycode == KEY_A)
		info->key_a = 1;
	else if (keycode == KEY_S)
		info->key_s = 1;
	else if (keycode == KEY_D)
		info->key_d = 1;
	return (0);
}

int key_release(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		info->key_w = 0;
	else if (keycode == KEY_A)
		info->key_a = 0;
	else if (keycode == KEY_S)
		info->key_s = 0;
	else if (keycode == KEY_D)
		info->key_d = 0;
	return (0);
}

int exit_press(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
	return (0);
}
