/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:40 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 10:43:26 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	init_default(t_info *info)
{
	info->map_width = 0;
	info->map_height = 0;
	info->player = 0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->color_flag = 0;
	info->dir_flag = 0;
	info->pos_flag = 0;
	info->list = create_list();
}

void
	init_info(t_info *info)
{
	int		i;

	init_default(info);
	i = -1;
	info->buf = (int **)ft_calloc(sizeof(int *) * SCREEN_H, 1);
	if (!info->buf)
		system_error("Malloc Error");
	while (++i < SCREEN_H)
	{
		info->buf[i] = (int *)ft_calloc(sizeof(int) * SCREEN_W, 1);
		if (!info->buf[i])
			system_error("Malloc Error");
	}
	i = -1;
	info->texture = (int **)ft_calloc(sizeof(int *) * 4, 1);
	if (!info->texture)
		system_error("Malloc Error");
	while (++i < 4)
	{
		info->texture[i] = \
			(int *)ft_calloc(sizeof(int) * (TEX_H * TEX_W), 1);
		if (!info->texture[i])
			system_error("Malloc Error");
	}
}

void
	init_map(t_info *info)
{
	int		i;

	i = -1;
	info->map = (char **)ft_calloc(sizeof(char *) * (info->map_height + 1), 1);
	if (!info->map)
		system_error("Malloc Error");
	while (++i < info->map_height)
	{
		info->map[i] = \
			(char *)ft_calloc(sizeof(char) * (info->map_width + 1), 1);
		if (!info->map[i])
			system_error("Malloc Error");
	}
}
