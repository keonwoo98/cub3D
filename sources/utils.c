#include "../includes/cub3d.h"

int
	ft_splitlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void
	free_double_int(int **arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

void
	free_double_char(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void
	free_list(t_info *info)
{
	t_node	*node;
	t_node	*temp;

	node = info->list->head;
	if (!node)
		return ;
	while (node)
	{
		free(node->map);
		temp = node;
		node = node->next;
		free(temp);
	}
	free(info->list);
}

void
	deinitialize(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	free_double_int(info->texture, 4);
	free_double_int(info->buf, screenHeight);
}
