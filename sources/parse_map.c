/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:55 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 10:21:20 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int
	check_map_content(t_info *info, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (info->pos_flag)
			return (RETURN_FAILURE);
		info->pos_flag = 1;
		return (RETURN_SUCCESS);
	}
	else if (c == ' ' || c == '0' || c == '1')
		return (RETURN_SUCCESS);
	return (RETURN_FAILURE);
}

int
	check_map(t_info *info, char *line, int size)
{
	int		i;

	i = -1;
	if (info->list->head == NULL)
	{
		while (++i < size)
		{
			if (line[i] != '1' && line[i] != ' ')
				return (RETURN_FAILURE);
		}
	}
	else
	{
		while (++i < size)
		{
			if (check_map_content(info, line[i]))
				return (RETURN_FAILURE);
		}
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] != '1' && line[size - 1] != '1')
			return (RETURN_FAILURE);
	}
	return (RETURN_SUCCESS);
}

void
	parse_map(char *line, t_info *info)
{
	int		size;
	t_node	*node;

	size = ft_strlen(line);
	if (check_map(info, line, size))
		exit_error("Map: Invalid Map Value\n");
	node = create_node(line);
	add_node(info->list, node);
	if (info->map_width < size)
		info->map_width = size;
	info->map_height++;
}

void
	parse_last(t_info *info, char *line)
{
	t_node	*node;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(line);
	while (i < size)
	{
		if (line[i] != '1' && line[i] != ' ')
			exit_error("Map: Invalid Last Line\n");
		i++;
	}
	node = create_node(line);
	add_node(info->list, node);
	if (info->map_width < size)
		info->map_width = size;
	info->map_height++;
}
