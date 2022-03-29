#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx/mlx.h"
#include "../Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>

# define RETURN_SUCCESS 0
# define RETURN_FAILURE 1

# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24
# define screenWidth 1280
# define screenHeight 720

# define MAX_FD 256
# define BUFFER_SIZE 1024

# define FLOOR 0
# define CEILING 1

enum e_key {
	KEY_ESC = 53,
	KEY_EVENT_PRESS = 2,
	KEY_EVENT_RELEASE = 3,
	KEY_EVENT_EXIT = 17,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};

enum e_dir {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

// # define RED 0xFF0000
// # define GREEN 0x00FF00
// # define BLUE 0x0000FF
// # define BLACK 0x000000
// # define WHITE 0xFFFFFF
// # define YELLOW 0xFFFF00
// # define GREY 0x7F7F7F
// # define GOLD 0xFFD700
// # define SILVER 0xC0C0C0
// # define SKYBLUE 0x87CEEB

typedef struct s_node t_node;

typedef struct s_node
{
	char *map;
	t_node *next;
}t_node;

typedef struct s_maplist
{
	int			size;
	t_node		*head;
	t_node		*tail;
}t_maplist;

typedef struct s_ray
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
}t_ray;

typedef struct s_img
{
	void *img;
	char *img_addr;
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
	int **buf;
	int **texture;
	char **map;
	int map_width;
	int map_height;
	int key_a;
	int key_w;
	int key_s;
	int key_d;
	int player;
	int color_flag;
	int dir_flag;
	int pos_flag;
	int floor;
	int ceiling;
	t_img img;
    t_ray ray;
	t_maplist *list;
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

/*
**	get_next_line.c
*/
int			get_next_line(int fd, char **line);
/*
**	ft_strjoin_free.c
*/
char		*ft_strjoin_free(char *s1, char *s2);
/*
**	init.c
*/
void		init_info(t_info *info);
void		init_map(t_info *info);
/*
**	key_press.c
*/
int			key_press(int keycode, t_info *info);
int			key_release(int keycode, t_info *info);
void		player_move(t_info *info);
/*
**	list.c
*/
t_maplist	*create_list(void);
t_node		*create_node(char *line);
void		add_node(t_maplist *list, t_node *node);
/*
**	parse.c
*/
void		parse(int argc, char **argv, t_info *info);
void		load_texture(t_info *info, int dir, char *path);
/*
**	parse_map.c
*/
void		parse_map(char *line, t_info *info);
void		parse_last(t_info *info, char *line);
/*
**	parse_color.c
*/
void		get_background_color(char *line, t_info *info, int flag);
/*
**	get_texture.c
*/
int			get_textures(char *line, t_info *info);
/*
**	get_map_info.c
*/
void		dup_map(t_info *info);
void		get_map_info(t_info *info);
/*
**	player_position.c
*/
void		player_position(t_info *info, int i, int j);
/*
**	ray.c
*/
void		init_dda(t_info *info, t_calc *calc);
void		perform_dda(t_info *info, t_calc *calc);
void		start_ray(int x, t_info *info, t_calc *calc);
/*
**	texture.c
*/
void		init_wall_texture(t_info *info, t_calc *calc);
void		input_wall_texture(int x, t_info *info, t_calc *calc);
/*
**	error.c
*/
void		exit_error(char *err_msg);
void		system_error(char *err_msg);
/*
**	utils.c
*/
int			ft_splitlen(char **str);
void		free_double_char(char **str);
void		free_list(t_info *info);
void		deinitialize(t_info *info);
void		exit_error(char *err_msg);
void		system_error(char *err_msg);

#endif
