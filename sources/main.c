#include "../includes/cub3d.h"

int
	exit_press(t_info *info)
{
	free_double_char(info->map);
	deinitialize(info);
	exit(EXIT_SUCCESS);
}

void
	draw(t_info *info)
{
	int		x;
	int		y;

	y = -1;
	while (++y < screenHeight)
	{
		x = -1;
		while (++x < screenWidth)
			info->img.data[y * screenWidth + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void
	calc(t_info *info)
{
	int		x;
	t_calc	calc;

	x = 0;
	while (x < screenWidth)
	{
		start_ray(x, info, &calc);
		init_dda(info, &calc);
		perform_dda(info, &calc);
		init_wall_texture(info, &calc);
		input_wall_texture(x, info, &calc);
		x++;
	}
}

int
	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	player_move(info);
	return (0);
}

int
	main(int argc, char **argv)
{
	t_info	info;

	info.mlx = mlx_init();
	init_info(&info);
	parse(argc, argv, &info);
	init_map(&info);
	dup_map(&info);
	get_map_info(&info);
	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "Cub3D");
	info.img.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
	info.img.data = (int *)mlx_get_data_addr \
		(info.img.img, &info.img.bpp, &info.img.line_size, &info.img.endian);
	mlx_hook(info.win, KEY_EVENT_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, KEY_EVENT_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, KEY_EVENT_EXIT, 0, &exit_press, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
