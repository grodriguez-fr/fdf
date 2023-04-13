/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:23:24 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 15:56:04 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"


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

int	init_map(t_fdf **map, char *arg)
{
	float	max;

	(*map) = malloc(sizeof(t_fdf));
	if (!(*map))
		exit(0);
	(*map)->cam = 0;
	if(!parse_map(*map, arg))
		exit_app(*map, 2);
	(*map)->mlx= mlx_init();
	(*map)->win= mlx_new_window((*map)->mlx, SCREEN_W, SCREEN_H, "FdF");
	(*map)->cam = malloc(sizeof(t_camera));
	if (!(*map)->cam)
		exit_app(*map, 2);
	max = (float)(*map)->dimx;
	if ((*map)->dimy > (*map)->dimx)
		max = (float)(*map)->dimy;
	if (!init_cam((*map)->cam, 27/19.0*max, 27/19.0*max, -30/19.0*max, max/25))
		exit_app(*map, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*map;

	map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number\n", 2), 1);
	if (!init_map(&map, argv[1]))
		return (exit_app(map, 2), 1);
	render_screen(map);
	mlx_key_hook(map->win, deal_key, map);
	mlx_hook(map->win, 17, 1L >> 17, exitmlx, map);
	mlx_loop(map->mlx);
	return (0);
}
