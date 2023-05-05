/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:12:06 by gurodrig          #+#    #+#             */
/*   Updated: 2023/05/05 08:12:32 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static float	absf(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	max_size_map(t_fdf *map)
{
	unsigned int	i;
	unsigned int	j;
	float			max;

	i = 0;
	max = (float)map->dimx;
	while (i < map->dimy)
	{
		j = 0;
		while (j < map->dimx)
		{
			if (absf(map->map[i][j].tab[2]) > max)
				max = absf(map->map[i][j].tab[2]);
			j++;
		}
		i++;
	}
	if ((float)map->dimy > max)
		max = (float)map->dimy;
	else if ((float) map->dimx != max)
		max *= 4;
	return (max);
}
