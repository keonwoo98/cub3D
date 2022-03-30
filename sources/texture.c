/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:21:07 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 10:45:13 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	init_wall_texture(t_info *info, t_calc *calc)
{
	calc->lineHeight = (int)(SCREEN_H / calc->perpWallDist);
	calc->drawStart = -calc->lineHeight / 2 + SCREEN_H / 2;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	calc->drawEnd = calc->lineHeight / 2 + SCREEN_H / 2;
	if (calc->drawEnd >= SCREEN_H)
		calc->drawEnd = SCREEN_H - 1;
	if (calc->rayDirX > 0 && calc->side == 0)
		calc->texNum = SO;
	else if (calc->rayDirX < 0 && calc->side == 0)
		calc->texNum = NO;
	else if (calc->rayDirY > 0 && calc->side == 1)
		calc->texNum = EA;
	else
		calc->texNum = WE;
	if (calc->side == 0)
		calc->wallX = info->ray.posY + calc->perpWallDist * calc->rayDirY;
	else
		calc->wallX = info->ray.posX + calc->perpWallDist * calc->rayDirX;
	calc->wallX -= floor(calc->wallX);
	calc->texX = (int)(calc->wallX * (double)TEX_W);
	if (calc->side == 0 && calc->rayDirX > 0)
		calc->texX = TEX_W - calc->texX - 1;
	if (calc->side == 1 && calc->rayDirY < 0)
		calc->texX = TEX_W - calc->texX - 1;
}

void
	input_wall_texture(int x, t_info *info, t_calc *calc)
{
	int		y;
	int		color;

	calc->step = 1.0 * TEX_H / calc->lineHeight;
	calc->texPos = (calc->drawStart - SCREEN_H / 2 \
		+ calc->lineHeight / 2) * calc->step;
	y = -1;
	while (++y < SCREEN_H)
	{
		if (y >= calc->drawStart && y <= calc->drawEnd)
		{
			calc->texY = (int)calc->texPos & (TEX_H - 1);
			calc->texPos += calc->step;
			color = info->texture[calc->texNum] \
				[TEX_H * calc->texY + calc->texX];
			if (calc->side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		else if (y < calc->drawStart)
			info->buf[y][x] = info->ceiling;
		else
			info->buf[y][x] = info->floor;
	}
}
