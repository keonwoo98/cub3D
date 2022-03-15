#include "../includes/cub3d.h"

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
