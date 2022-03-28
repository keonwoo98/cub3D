#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx/mlx.h"
#include "../Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>

# define PI 3.14159265359

# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

# define KEY_ESC 53
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_RELEASE 3
# define KEY_EVENT_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define GREY 0x7F7F7F
# define GOLD 0xFFD700
# define SILVER 0xC0C0C0
# define SKYBLUE 0x87CEEB

# define MAX_FD 1024
# define BUFFER_SIZE 512

int testMap[mapWidth][mapHeight];

typedef struct s_vec
{
    double x;
    double y;
}t_vec;

typedef struct s_ray
{
	double posX;
	double posY;	// 플레이어의 초기 위치벡터
	double dirX;
	double dirY;	// 플레이어의 초기 방향벡터
	double planeX;	// 플레이어의 카메라 평면
	double planeY;	// FOV는 "카메라 평면의 길이 : 방향벡터의 길이"의 비율로 결정됨
	double moveSpeed;
	double rotSpeed;
}t_ray;

typedef struct s_img
{
	void *img;
	int *data;
	int line_size;
	int bpp;
	int endian;
	int img_width;
	int img_height;
}t_img;

typedef struct s_info
{
	void *mlx;
	void *win;
    int map[mapWidth][mapHeight];
	// int **map;
	int **buf;
	int **texture;
	int key_a;
	int key_w;
	int key_s;
	int key_d;
	t_img img;
    t_ray ray;
}t_info;

typedef struct s_calc
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int texNum;
	double wallX;
	int texX;
	int texY;
	double step;
	double texPos;
	double spriteX;
	double spriteY;
}t_calc;

int get_next_line(int fd, char **line);
void init_info(t_info *info);
int parsing(int argc, char **argv, t_info *info);
void load_texture(t_info *info);
void init_dda(t_info *info, t_calc *calc);
void perform_dda(t_info *info, t_calc *calc);
void start_ray(int x, t_info *info, t_calc *calc);
void init_wall_texture(t_info *info, t_calc *calc);
void input_wall_texture(int x, t_info *info, t_calc *calc);
void player_move(t_info *info);
int key_press(int keycode, t_info *info);
int key_release(int keycode, t_info *info);
int exit_press(t_info *info);

#endif
