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

int	main(int argc, char **argv)
{
	t_fdf	*map;

	map = malloc(sizeof(t_fdf));
	if (!map)
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number\n", 2), 1);
	map->mlx= mlx_init();
	map->win= mlx_new_window(map->mlx, SCREEN_W, SCREEN_H, "FdF");
	parse_map(map, argv[1]);
	map->cam = malloc(sizeof(t_camera));
	if (!map->cam)
		return (free(map), ft_putstr_fd("Malloc failed\n", 2), 1);
	init_cam(map->cam, 10, 10, -20);
	draw_map(map);
	mlx_loop(map->mlx);
	return (0);
}
