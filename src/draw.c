#include "fdf.h"

int	init_draw(t_draw *d, t_fdf *map)
{
	int	check;

	d->i = 0;
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

void	free_draw(t_draw *d)
{
	free_mat4(d->projection);
	free_mat4(d->cammat);
	free_mat4(d->screen);
	free_v(d->res);
	free_v(d->res2);
}

void	draw_map(t_fdf *map)
{
	t_draw		d;
	unsigned int	j;

	if (!init_draw(&d, map))
		return (exit_map(map), 0);
	while (d.i < map->dimy)
	{
		j = 0;
		while (j < map->dimx)
		{
			if (!proj_vec(d.projection, d.cammat, d.screen, &map->map[d.i][j], d.res))
				return (free_draw(&d), exit_map(), 0);
			if (d.i + 1 < map->dimy)
			{
				if(!proj_vec(d.projection, d.cammat, d.screen, &map->map[d.i + 1][j], d.res2))
					return (free_draw(&d), exit_map(), 0);
				draw_line(map, d.res, d.res2);	
			}
			if (j + 1 < map->dimx)
			{
				if(!proj_vec(d.projection, d.cammat, d.screen, &map->map[d.i][j + 1], d.res2))
					return (free_draw(&d), exit_map(), 0);
				draw_line(map, d.res, d.res2);	
			}
			j++;
		}
		d.i = d.i + 1;
	}
	return (1, free_draw(&d));
}

void	my_mlx_put_pixel(t_fdf *map, int x, int y)
{
	if (y > SCREEN_H || y < 0)
		return;
	if (x > SCREEN_W || x < 0)
		return;
	map->img.addr[y * SCREEN_W + x] = 0x00FFFFFF;
}

void	render_screen(t_fdf *map)
{
	map->img.img = mlx_new_image(map->mlx, SCREEN_W, SCREEN_H);
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, \
			&map->img.line_length, &map->img.endian);
	draw_map(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	mlx_destroy_image(map->mlx, map->img.img);
}
