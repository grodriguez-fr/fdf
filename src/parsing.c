/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:08:07 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 11:50:02 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	write_error()
{
	ft_putstr_fd("Error while opening file :", 2);
	return (ft_putstr_fd(strerror(errno), 2), 0);
}

int	parse_map(t_fdf *map, const char *filename)
{
	int	fd;
	int	closed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write_error());
	map->dimx = 0;
	closed = close(fd);
	if (closed == -1)
		return (write_error());
	return (1);
}
