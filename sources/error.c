#include "../includes/cub3d.h"

void
	exit_error(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void
	system_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}
