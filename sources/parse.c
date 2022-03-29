#include "../includes/cub3d.h"

void
	check_arg(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		exit_error("Input Argument Error\n");
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".cub", 4))
		exit_error("File Extension Error\n");
}

void
	parse_line(t_info *info, char *line)
{
	if (info->dir_flag > 4 || info->color_flag > 2)
		exit_error(".cub: Too Much Information Error\n");
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) || \
		!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		get_textures(line, info);
	else if (!ft_strncmp(line, "F ", 2))
		get_background_color(line, info, FLOOR);
	else if (!ft_strncmp(line, "C ", 2))
		get_background_color(line, info, CEILING);
	else if (ft_strlen(line) <= 0)
		return ;
	else if (info->color_flag == 2 && info->dir_flag == 4)
		parse_map(line, info);
	else
		exit_error(".cub: Invalid Identifier Error\n");
}

void
	parse_cub(int fd, t_info *info)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			exit_error("GNL Error\n");
		parse_line(info, line);
		free(line);
	}
	parse_last(info, line);
	free(line);
	if (info->dir_flag != 4 || info->color_flag != 2 || info->pos_flag != 1)
		exit_error(".cub: Too Few Information\n");
}

void
	parse(int argc, char **argv, t_info *info)
{
	int		fd;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Map Path Error\n");
	parse_cub(fd, info);
	close(fd);
}
