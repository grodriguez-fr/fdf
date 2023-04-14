/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:48:49 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 13:20:26 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_map(t_fdf *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->map && i < map->dimy)
	{
		j = 0;
		while (map->map[i] && j < map->dimx)
		{
			if (map->map[i][j].tab)
				free(map->map[i][j].tab);
			j++;
		}
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
}

int	exit_app(t_fdf *map, int error)
{
	if (!map)
		return (exit(error), 1);
	free_map(map);
	free_cam(map->cam);
	if (map->mlx && map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map);
	if (error == 2)
		ft_putstr_fd("Error : malloc failed\n", 2);
	if (error == 3)
		ft_putstr_fd("Error : map not well formated\n", 2);
	return (exit(error), 1);
}

void	render_screen(t_fdf *map)
{
	map->img.img = mlx_new_image(map->mlx, SCREEN_W, SCREEN_H);
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, \
			&map->img.bits_per_pixel, \
			&map->img.line_length, &map->img.endian);
	draw_map(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	mlx_destroy_image(map->mlx, map->img.img);
}

int	init_map(t_fdf **map, char *arg)
{
	float	max;
	int		ret;

	(*map) = malloc(sizeof(t_fdf));
	if (!(*map))
		exit(0);
	(*map)->cam = 0;
	ret = parse_map(*map, arg);
	if (ret != 1)
		exit_app(*map, ret);
	(*map)->mlx = mlx_init();
	(*map)->win = mlx_new_window((*map)->mlx, SCREEN_W, SCREEN_H, "FdF");
	(*map)->cam = malloc(sizeof(t_camera));
	if (!(*map)->cam)
		exit_app(*map, 2);
	max = (float)(*map)->dimx;
	if ((*map)->dimy > (*map)->dimx)
		max = (float)(*map)->dimy;
	if (!init_cam((*map)->cam, 27 / 19.0 * max, -30 / 19.0 * max, max / 25))
		exit_app(*map, 2);
	return (1);
}
