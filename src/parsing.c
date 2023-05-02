/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:08:07 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 15:17:39 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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
		free(line);
		line = get_next_line(fd);
	}
	map->dimx = dimx;
	map->dimy = dimy;
	return (1);
}

static int	malloc_fdf(t_fdf *map)
{
	unsigned int	i;
	unsigned int	j;

	map->map = malloc(sizeof(t_vector4 *) * map->dimy);
	if (!map->map)
		return (0);
	i = 0;
	while (i < map->dimy)
	{
		j = 0;
		map->map[i] = malloc(sizeof(t_vector4) * map->dimx);
		if (!map->map[i])
			return (0);
		while (j < map->dimx)
		{
			map->map[i][j].tab = malloc(sizeof(float) * 4);
			if (!map->map[i][j].tab)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	fill_map(t_fdf *map, int fd)
{
	char	*line;
	char	**splited;
	int		i;
	int		j;

	line = get_next_line(fd);
	if (!line)
		return (0);
	splited = ft_split(line, ' ');
	i = -1;
	while (++i < (int)map->dimy)
	{
		if (!splited)
			return (0);
		j = -1;
		while (++j < (int)map->dimx)
			set_vector(map, ft_atoi(splited[j]), i, j);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (free_splited(splited), free(line), i + 1 == (int)map->dimy);
		free_splited(splited);
		splited = ft_split(line, ' ');
	}
	return (free_splited(splited), free(line), 1);
}

int	parse_map(t_fdf *map, const char *filename)
{
	int	fd;

	map->map = 0;
	map->dimx = 0;
	map->dimy = 0;
	map->cam = 0;
	map->mlx = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write_error());
	if (!set_dimension(map, fd))
		return (3);
	if (close(fd) == -1)
		return (write_error());
	fd = open(filename, O_RDONLY);
	if (!malloc_fdf(map))
		return (2);
	if (!fill_map(map, fd))
		return (2);
	if (close(fd) == -1)
		return (write_error());
	return (1);
}
