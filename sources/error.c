/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:19 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 22:16:49 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void
	free_exit_error(char **str, char *err_msg)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

int
	free_return_error(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (RETURN_FAILURE);
}
