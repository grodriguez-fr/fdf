/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:40:55 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:04 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_draw(t_draw *d)
{
	free_mat4(d->projection);
	free_mat4(d->cammat);
	free_mat4(d->screen);
	free_v(d->res);
	free_v(d->res2);
}

int	init_draw(t_draw *d, t_fdf *map)
{
	int	check;

	d->i = 0;
	d->j = 0;
	check = 0;
	check += init_mat4(&d->projection);
	check += init_mat4(&d->cammat);
	check += init_mat4(&d->screen);
	check += init_vec4(&d->res);
	check += init_vec4(&d->res2);
	if (check != 5)
		return (free_draw(d), 0);
	projection_matrix(map->cam, d->projection);
	if (!camera_matrix(map->cam, d->cammat))
		return (free_draw(d), 0);
	camera_screen_matrix(d->screen);
	return (1);
}

int	draw_map_help(t_draw *d, t_fdf *map)
{
	if (!proj_vec(d, &map->map[d->i][d->j], d->res))
		return (exit_app(map, 2), 0);
	if (d->i + 1 < map->dimy)
	{
		if (!proj_vec(d, &map->map[d->i + 1][d->j], d->res2))
			return (exit_app(map, 2), 0);
		draw_line(map, d->res, d->res2);
	}
	if (d->j + 1 < map->dimx)
	{
		if (!proj_vec(d, &map->map[d->i][d->j + 1], d->res2))
			return (exit_app(map, 2), 0);
		draw_line(map, d->res, d->res2);
	}
	return (1);
}

void	draw_map(t_fdf *map)
{
	t_draw		d;

	if (!init_draw(&d, map))
		exit_app(map, 2);
	while (d.i < map->dimy)
	{
		d.j = 0;
		while (d.j < map->dimx)
		{
			draw_map_help(&d, map);
			d.j = d.j + 1;
		}
		d.i = d.i + 1;
	}
	free_draw(&d);
}

void	my_mlx_put_pixel(t_fdf *map, int x, int y)
{
	if (y >= SCREEN_H || y < 0)
		return ;
	if (x >= SCREEN_W || x < 0)
		return ;
	map->img.addr[y * SCREEN_W + x] = 0x00FF0000;
}
