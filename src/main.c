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
	t_mat4	*projection;
	t_mat4	*screen;
	t_mat4	*cammat;
	t_vector4 *res;
	unsigned int	i;
	unsigned int	j;

	map = malloc(sizeof(t_fdf));
	if (!map)
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Wrong arg number\n", 2), 1);
	map->mlx= mlx_init();
	map->win= mlx_new_window(map->mlx, SCREEN_W, SCREEN_H, "FdF");
	parse_map(map, argv[1]);
	map->cam = malloc(sizeof(t_camera));
	init_mat4(&projection);
	init_mat4(&cammat);
	init_mat4(&screen);
	init_vec4(&res);
	init_cam(map->cam, 10, 10, -20);
	projection_matrix(map->cam, projection);
	camera_matrix(map->cam, cammat);
	camera_screen_matrix(screen);
	i = 0;
	while (i < map->dimy)
	{
		j = 0;
		while (j < map->dimx)
		{
			proj_vec(projection, cammat, screen, &map->map[i][j], res);
			printf("avant pixel_put : %f %f\n", res->tab[0], res->tab[1]);	
			mlx_pixel_put(map->mlx, map->win, res->tab[0], res->tab[1], 0x00FFFFFF);
			j++;
			printf("------------------------------------------------\n");
		}
		i++;	
	}
	mlx_loop(map->mlx);
	return (0);
}
