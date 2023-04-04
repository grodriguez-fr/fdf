/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:08:07 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 15:59:15 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	write_error(void)
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
	int		dimx;	
	int		dimy;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	dimx = numbers_per_line(line);
	dimy = 0;
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
#include <stdio.h>
static int	fill_map(t_fdf *map, int fd)
{
	char	*line;
	char	**splited;
	int			i;
	int			j;

	line = get_next_line(fd);
	if (!line)
		return (0);
	splited = ft_split(line, ' ');
	i = 0;
	while (i < (int)map->dimy)
	{
		map->map[i] = malloc(sizeof(int *) * map->dimx);
		if (!map->map[i])
			return (0);
		j = -1;
		while (++j < (int)map->dimx)
			map->map[i][j] = ft_atoi(splited[j]);
		line = get_next_line(fd);
		if (!line)
			return (0);
		splited = ft_split(line, ' ');
		i++;	
	}
	return (1);
}
int	parse_map(t_fdf *map, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write_error());
	if (!set_dimension(map, fd))
		return (0);
	if (close(fd) == -1)
		return (write_error());
	map->map = malloc(sizeof(int *) * map->dimy);
	if (!map->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (!fill_map(map, fd))
		return (0);
	if (close(fd) == -1)
		return (write_error());
	return (1);
}
