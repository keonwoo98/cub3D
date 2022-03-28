#include "../includes/cub3d.h"

int check_arg(int argc, char **argv, t_info *info)
{
	int i;

	if (argc != 2)
	{
		ft_putstr_fd("input error\n", 2);
		return (1);
	}
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".cub", 4))
	{
		ft_putstr_fd("input error\n", 2);
		return (1);
	}
	return (0);
}

int parse_map(int fd, t_info *info)
{
	char *line;

	// parse texture, color, space, etc..
	while (get_next_line(fd, &line) > -1)
	{
		if (line[0] == 'R' || line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
				|| line[0] == 'E')
		{
			// texture
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			// color
		}
		else
		{
			// space
		}
		free(line);
	}
	free(line);
	return (0);
}

int parsing(int argc, char **argv, t_info *info)
{
	int fd;

	if (check_arg(argc, argv, info))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (1);
	// if (parse_map(fd, info))
	// 	return (1);
	close(fd);
	return (0);
}
