#include "../includes/cub3d.h"

void rotate_matrix(t_vec *vec, double angle)
{
	double tmp;

	tmp = cos(angle) * vec->x - sin(angle) * vec->y;
	vec->y = sin(angle) * vec->x + cos(angle) * vec->y;
	vec->x = tmp;
}

int key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_LEFT)
		rotate_matrix(&info->dir_vec, PI / 36);
	if (keycode == KEY_RIGHT)
		rotate_matrix(&info->dir_vec, -PI / 36);
	return (0);
}

int exit_button(void)
{
	exit(EXIT_SUCCESS);
}

void init_ray(t_ray *ray)
{
	ray->posX = 22.0;
	ray->posY = 11.5;	// 플레이어의 초기 위치벡터
	ray->dirX = -1.0;
	ray->dirY = 0.0;	// 플레이어의 초기 방향벡터
	ray->planeX = 0.0;	// 플레이어의 카메라 평면
	ray->planeY = 0.66;	// FOV는 "카메라 평면의 길이 : 방향벡터의 길이"의 비율로 결정됨
	ray->time = 0;	// 현재 프레임 시간
	ray->oldTime = 0;	// 이전 프레임 시간
}

void init_info(t_info *info)
{
	info->win_width = 0;
	info->win_height = 0;
	info->bmp = 0;
	init_ray(&info->ray);
	info->dir_vec.x = 0.0;
	info->dir_vec.y = 0.0;

	// test case
	info->win_width = mapWidth;
	info->win_height = mapHeight;
	memcpy(info->map, testMap, sizeof(int) * mapWidth * mapHeight);
	// test case
}


int check_arg(int argc, char **argv, t_info *info)
{
	int i;

	if (argc < 2 || argc > 4)
	{
		ft_putstr_fd("input error\n", 2);
		return (EXIT_FAILURE);
	}
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".cub", 4))
	{
		ft_putstr_fd("input error\n", 2);
		return (EXIT_FAILURE);
	}
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || ft_strncmp(argv[2], "--save", 6))
		{
			ft_putstr_fd("invalid arg\n", 2);
			return (EXIT_FAILURE);
		}
		else
			info->bmp = 1;
	}
	return (EXIT_SUCCESS);
}

int parse_map(int fd, t_info *info)
{
	char *line;

	// parse texture, color, space, etc..
	return (EXIT_SUCCESS);
}

int parsing(int argc, char **argv, t_info *info)
{
	int fd;

	if (check_arg(argc, argv, info))
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (EXIT_FAILURE);
	if (parse_map(fd, info))
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

void draw_hor_line(int x, t_info *info)
{
	int i;
	int width;

	width = info->win_height * T_SIZE;
	i = -1;
	while (++i < width)
		info->data[width * x + i] = GRAY;
}

void draw_ver_line(int y, t_info *info)
{
	int i;
	int width;
	int height;

	width = info->win_height * T_SIZE;
	height = info->win_width * T_SIZE;
	i = -1;
	while (++i < height)
		info->data[width * i + y] = GRAY;
}

void draw_line(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->win_width)
		draw_hor_line(i * T_SIZE, info);
	i = -1;
	while (++i < info->win_height)
		draw_ver_line(i * T_SIZE, info);
}

void draw_square(int x, int y, t_info *info, int color)
{
	int dx;
	int dy;
	int width;

	width = info->win_height * T_SIZE;
	dx = -1;
	while (++dx < T_SIZE)
	{
		dy = -1;
		while (++dy < T_SIZE)
			info->data[width * (x + dx) + (y + dy)] = color;
	}
}

void draw_squares(t_info *info)
{
	int x;
	int y;

	x = -1;
	while (++x < info->win_width)
	{
		y = -1;
		while (++y < info->win_height)
		{
			if (info->map[x][y] == 0)
				draw_square(x * T_SIZE, y * T_SIZE, info, WHITE);
			else
				draw_square(x * T_SIZE, y * T_SIZE, info, BLACK);
		}
	}
}

void draw_ray(t_info *info, double angle)
{
	double ray_x;
	double ray_y;
	double dx;
	double dy;
	double max_value;

	ray_x = 22.0 * T_SIZE;
	ray_y = 11.5 * T_SIZE;
	dx = cos(angle) * info->ray.dirX - sin(angle) * info->ray.dirY;
	dy = sin(angle) * info->ray.dirX + cos(angle) * info->ray.dirY;
	max_value = fmax(fabs(dx), fabs(dy));
	dx /= max_value;
	dy /= max_value;
	while (1)
	{
		if (info->data[mapWidth * (int)floor(ray_y) + (int)floor(ray_x)] != BLACK)
			info->data[mapWidth * (int)floor(ray_y) + (int)floor(ray_x)] = RED;
		// if (info->map[(int)(ray_x / T_SIZE)][(int)(ray_y / T_SIZE)] != BLACK)
		// 	info->map[(int)(ray_x / T_SIZE)][(int)(ray_y / T_SIZE)] = RED;
		else
			break ;
		ray_x += dx;
		ray_y += dy;
	}
}

void draw_rays(t_info *info)
{
	double angle;

	angle = 0;
	while (angle < PI / 6)
	{
		draw_ray(info, angle);
		draw_ray(info, -angle);
		angle += PI / 72;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int main_loop(t_info *info)
{
	draw_squares(info);
	draw_line(info);
	draw_rays(info);
	// draw_player(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_info info;

	init_info(&info);
	if (parsing(argc, argv, &info))
		return (-1);

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.win_width * T_SIZE, info.win_height * T_SIZE, "Cub3D");
	info.img = mlx_new_image(info.mlx, info.win_width * T_SIZE, info.win_height * T_SIZE);
	info.data = (int *)mlx_get_data_addr(info.img, &info.bpp, &info.line_size, &info.endian);
	mlx_hook(info.win, KEY_EVENT_PRESS, 0, key_press, &info);
	mlx_hook(info.win, KEY_EVENT_EXIT, 0, exit_button, &info);
	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
