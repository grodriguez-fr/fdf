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

int	exitmlx(void *arg)
{
	t_fdf *map;

	map = arg;
	exit_app(map);
	return (1);
}
int	init_map(t_fdf **map, char *arg)
{
	float	max;

	(*map) = malloc(sizeof(t_fdf));
	if (!(*map))
		return (0);
	(*map)->mlx= mlx_init();
	(*map)->win= mlx_new_window((*map)->mlx, SCREEN_W, SCREEN_H, "FdF");
	parse_map(*map, arg); 
	(*map)->cam = malloc(sizeof(t_camera));
	if (!(*map)->cam)
		return (0);
	max = (float)(*map)->dimx;
	if ((*map)->dimy > (*map)->dimx)
		max = (float)(*map)->dimy;
	init_cam((*map)->cam, 27/19.0*max, 27/19.0*max, -30/19.0*max, max/25);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*map;

	map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number\n", 2), 1);
	if (!init_map(&map, argv[1]))
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	printf("%d %d\n", map->dimx, map->dimy);
	render_screen(map);
	mlx_key_hook(map->win, deal_key, map);
	mlx_hook(map->win, 17, 1L >> 17, exitmlx, map);
	mlx_loop(map->mlx);
	return (0);
}
