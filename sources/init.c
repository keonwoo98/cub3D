#include "../includes/cub3d.h"

void load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void load_texture(t_info *info)
{
	t_img img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

void init_ray(t_ray *ray)
{
	ray->posX = 22.0;
	ray->posY = 11.5;
	ray->dirX = -1.0;
	ray->dirY = 0.0;
	ray->planeX = 0.0;
	ray->planeY = 0.66;
	ray->moveSpeed = 0.05;
	ray->rotSpeed = 0.05;
}

void init_info(t_info *info)
{
	info->bmp = 0;
	init_ray(&info->ray);

	info->buf = (int **)malloc(sizeof(int *) * screenHeight);
	for (int i = 0; i < screenHeight; i++)
		info->buf[i] = (int *)malloc(sizeof(int) * screenWidth);
	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
			info->buf[i][j] = 0;
	}

	info->texture = (int **)malloc(sizeof(int *) * 8);
	for (int i = 0; i < 8; i++)
		info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
			info->texture[i][j] = 0;
	}
	load_texture(info);
	// for (int x = 0; x < texWidth; x++)
	// {
	// 	for (int y = 0; y < texHeight; y++)
	// 	{
	// 		int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
	// 		int ycolor = y * 256 / texHeight;
	// 		int xycolor = y * 128 / texHeight + x * 128 / texWidth;
	// 		info->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y);
	// 		info->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
	// 		info->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor;
	// 		info->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
	// 		info->texture[4][texWidth * y + x] = 256 * xorcolor;
	// 		info->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16);
	// 		info->texture[6][texWidth * y + x] = 65536 * ycolor;
	// 		info->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128;
	// 	}
	// }

	// for (int x = 0; x < screenWidth; x++)
	// {
	// 	for (int y = 0; y < screenHeight; y++)
	// 	{
	// 		info->buf[y][x] = 0xFFFFFF;
	// 		info->buf[screenHeight - y - 1][x] = 0x000000;
	// 		// buf[screenHeight - 1 ~ screenHeight - screenHeight][x] 를 칠해줌.
	// 	}
	// }
}
