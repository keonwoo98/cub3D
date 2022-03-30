/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:05 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 10:20:11 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	b_space(t_info *info, t_node *node, int i)
{
	int		j;

	j = ft_strlen(node->map);
	while (j < info->map_width)
	{
		info->map[i][j] = ' ';
		j++;
	}
	info->map[i][info->map_width] = '\0';
}

void
	dup_map(t_info *info)
{
	int		i;
	t_node	*node;
	t_node	*temp;

	node = info->list->head;
	i = 0;
	while (node)
	{
		ft_strlcpy(info->map[i], node->map, ft_strlen(node->map) + 1);
		if (ft_strlen(node->map) < (size_t)info->map_width)
			b_space(info, node, i);
		temp = node;
		node = node->next;
		free(temp->map);
		free(temp);
		info->list->size--;
		i++;
	}
	info->map[i] = NULL;
	free(info->list);
}

int
	check_position(t_info *info, int i, int j)
{
	if (i - 1 < 0 || j - 1 < 0 || \
		i + 1 > info->map_height || j + 1 > info->map_width)
		return (RETURN_FAILURE);
	if (info->map[i - 1][j] != '0' && info->map[i - 1][j] != '1')
		return (RETURN_FAILURE);
	if (info->map[i + 1][j] != '0' && info->map[i + 1][j] != '1')
		return (RETURN_FAILURE);
	if (info->map[i][j - 1] != '0' && info->map[i][j - 1] != '1')
		return (RETURN_FAILURE);
	if (info->map[i][j + 1] != '0' && info->map[i][j + 1] != '1')
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

int
	check_blank(t_info *info, int i, int j)
{
	if (i - 1 > 0)
		if (info->map[i - 1][j] != ' ' && info->map[i - 1][j] != '1')
			return (RETURN_FAILURE);
	if (j - 1 > 0)
		if (info->map[i][j - 1] != ' ' && info->map[i][j - 1] != '1')
			return (RETURN_FAILURE);
	if (i + 1 < info->map_height)
		if (info->map[i + 1][j] != ' ' && info->map[i + 1][j] != '1')
			return (RETURN_FAILURE);
	if (j + 1 < info->map_width)
		if (info->map[i][j + 1] != ' ' && info->map[i][j + 1] != '1')
			return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

void
	get_map_info(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		while (++j < info->map_width)
		{
			if (ft_isalpha(info->map[i][j]))
			{
				if (check_position(info, i, j))
					exit_error("Invalid map\n");
				player_position(info, i, j);
			}
			else if (info->map[i][j] == ' ')
				if (check_blank(info, i, j))
					exit_error("Invalid map\n");
		}
	}
}
