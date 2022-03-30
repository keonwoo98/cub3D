/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:20:19 by keokim            #+#    #+#             */
/*   Updated: 2022/03/30 10:20:23 by keokim           ###   ########.fr       */
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
