/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:12:06 by gurodrig          #+#    #+#             */
/*   Updated: 2023/05/05 10:11:04 by gurodrig         ###   ########.fr       */
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

void	reinit_cam(t_fdf *map)
{
	float max;

	init_iso(map->cam);
	max = max_size_map(map);
	map->cam->position->tab[0] = 27 / 19.0 * max;
	map->cam->position->tab[1] = 27 / 19.0 * max;
	map->cam->position->tab[2] = -30 / 19.0 * max;
}

int	proj_vec_iso(t_draw *d, t_vector4 *e, t_vector4 *s)
{
	float	nx;
	float	ny;

	d->cammat->tab[0][0] = 0;
	nx = 0.70710678118 * (e->tab[0] - e->tab[1]);
	ny = 0.81649658092 * e->tab[2] - 0.40824829046 * (e->tab[0] + e->tab[1]);
	s->tab[0] = nx;
	s->tab[1] = ny;
	normalize_vec(s);
	s->tab[0] = s->tab[0] * 40 + 800;
	s->tab[1] = s->tab[1] * 40 + 500;
	return (1);
}
