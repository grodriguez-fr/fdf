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

	map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number, usage : ./fdf [filename]\n", 2), 1);
	if (!init_map(&map, argv[1]))
		return (exit_app(map, 2), 1);
	render_screen(map);
	mlx_key_hook(map->win, deal_key, map);
	mlx_hook(map->win, 17, 1L >> 17, exitmlx, map);
	mlx_loop(map->mlx);
	return (0);
}
