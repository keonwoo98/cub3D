/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:37 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 12:50:59 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	load_image(t_info *info, int *texture, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = \
	mlx_xpm_file_to_image(info->mlx, path, &img.img_width, &img.img_height);
	img.data = \
	(int *)mlx_get_data_addr(img.img, &img.bpp, &img.line_size, &img.endian);
	y = -1;
	while (++y < img.img_height)
	{
		x = -1;
		while (++x < img.img_width)
			texture[img.img_width * y + x] = img.data[img.img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img.img);
}

void
	load_texture(t_info *info, int dir, char *path)
{
	load_image(info, info->texture[dir], path);
}

int
	check_extension(char *filename, char *extension)
{
	if (!filename)
		return (EXIT_FAILURE);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, extension, 4))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int
	get_texture(char *line, t_info *info, int dir)
{
	int		fd;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		system_error("Malloc Error");
	if (ft_splitlen(split) != 2 || check_extension(split[1], ".xpm"))
	{
		free_double_char(split);
		return (RETURN_FAILURE);
	}
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
		return (RETURN_FAILURE);
	load_texture(info, dir, split[1]);
	free_double_char(split);
	info->dir_flag++;
	return (RETURN_SUCCESS);
}

int
	get_textures(char *line, t_info *info)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (get_texture(line, info, NO))
			exit_error("Map: Invalid Texture Value\n");
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (get_texture(line, info, EA))
			exit_error("Map: Invalid Texture Value\n");
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (get_texture(line, info, SO))
			exit_error("Map: Invalid Texture Value\n");
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (get_texture(line, info, WE))
			exit_error("Map: Invalid Texture Value\n");
	}
	return (RETURN_SUCCESS);
}
