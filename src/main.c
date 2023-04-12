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

int	rotate_camera(t_fdf *map, void (*rotate_fun) (t_mat4 *, float), float a)
{
	t_mat4 *rot;
	t_vector4 *copy;

	if (!init_mat4(&rot))
		return (0);
	if (!init_vec4(&copy))
		return (free_mat4(&rot), 0);
	rotate_fun(rot, a);
	vec_copy(copy, map->cam->up);
	multvec(copy, rot, map->cam->up);
	vec_copy(copy, map->cam->forward);
	multvec(copy, rot, map->cam->forward);
	vec_copy(copy, map->cam->right);
	multvec(copy, rot, map->cam->right);
	return (free_mat4(&rot), free_v(copy), 1);
}

int	deal_key(int key, void *param)
{
	t_fdf *map;

	map = param;
//	printf("key : %d\n", key);
	if (key == 'a')
		map->cam->position->tab[0] = map->cam->position->tab[0] - 0.2;
	if (key == 'd')
		map->cam->position->tab[0] = map->cam->position->tab[0] + 0.2;
	if (key == 'w')
		map->cam->position->tab[1] = map->cam->position->tab[1] + 0.2;
	if (key == 's')
		map->cam->position->tab[1] = map->cam->position->tab[1] - 0.2;
	if (key == 'i')
		map->cam->position->tab[2] = map->cam->position->tab[2] + 0.2;
	if (key == 'o')
		map->cam->position->tab[2] = map->cam->position->tab[2] - 0.2;
	if (key == KEY_LEFT)
		rotate_camera(map, &rotation_x_matrix, -0.015);
	if (key == KEY_RIGHT)
		rotate_camera(map, &rotation_x_matrix, 0.015);
	if (key == KEY_UP)
		rotate_camera(map, &rotation_y_matrix, -0.015);
	if (key == KEY_DOWN)
		rotate_camera(map, &rotation_y_matrix, 0.015);
	if (key == 'k')
		rotate_camera(map, &rotation_z_matrix, -0.015);
	if (key == 'l')
		rotate_camera(map, &rotation_z_matrix, 0.015);
	render_screen(map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*map;

	//initialisation
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
	// fin initialisation
	render_screen(map);
	mlx_key_hook(map->win, deal_key, map);
	mlx_loop(map->mlx);
	return (0);
}
