/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:08:07 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 15:46:47 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	write_error()
{
	ft_putstr_fd("Error while opening file : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

static int	numbers_per_line(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		if (line[i] && line[i] != '\n')
			nb++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (nb);
}

static int	set_dimension(t_fdf *map, int fd)
{
	int	dimx;	
	int	dimy;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	dimx = numbers_per_line(line); 
	dimy = 1;
	while (line)
	{
		dimy++;
		if (dimx != numbers_per_line(line))
			return (0);
		line = get_next_line(fd);
	}
	map->dimx = dimx;
	map->dimy = dimy;
	return (1);
}

int	parse_map(t_fdf *map, const char *filename)
{
	int	fd;
	int	closed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write_error());
	set_dimension(map, fd);
	ft_putstr_fd("x : ", 0);
	ft_putnbr_fd(map->dimx, 0);
	ft_putstr_fd("\ny : ", 0);
	ft_putnbr_fd(map->dimy, 0);
	closed = close(fd);
	if (closed == -1)
		return (write_error());
	return (1);
}
