#include "../includes/cub3d.h"

void load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
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
	int i;
	int j;

	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	init_ray(&info->ray);
	info->buf = (int **)malloc(sizeof(int *) * screenHeight);
	i = -1;
	while (++i < screenHeight)
		info->buf[i] = (int *)malloc(sizeof(int) * screenWidth);
	i = -1;
	while (++i < screenHeight)
	{
		j = -1;
		while (++j < screenWidth)
			info->buf[i][j] = 0;
	}
	info->texture = (int **)malloc(sizeof(int *) * 8);
	i = -1;
	while (++i < 8)
		info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < texHeight * texWidth)
			info->texture[i][j] = 0;
	}
	load_texture(info);
}
