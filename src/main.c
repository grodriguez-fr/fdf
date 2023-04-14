/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:23:24 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 17:56:34 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*map;

	map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Wrong args, usage : ./fdf [filename]\n", 2), 1);
	if (!init_map(&map, argv[1]))
		return (exit_app(map, 2), 1);
	render_screen(map);
	mlx_hook(map->win, 2, 1L << 0, deal_key, map);
	mlx_hook(map->win, 17, 1L >> 17, exitmlx, map);
	mlx_loop(map->mlx);
	return (0);
}
