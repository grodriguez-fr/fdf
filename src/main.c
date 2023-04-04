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
#include <mlx.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdf	*map;
	void	*mlx_ptr;
	void	*win_ptr;

	map = malloc(sizeof(t_fdf));
	if (!map)
		return (ft_putstr_fd("Malloc failed", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number\n", 2), 1);
	parse_map(map, argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FFFFFF);
	mlx_loop(mlx_ptr);
	return (0);
}
