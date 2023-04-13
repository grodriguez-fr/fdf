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
	return (exit(error), 1);
}


void	deal_key2(int key, t_fdf *map)
{
	if (key == KEY_LEFT)
		if (!rotate_camera(map, &rotation_x_matrix, -0.015))
			exit_app(map, 2);
	if (key == KEY_RIGHT)
		if (!rotate_camera(map, &rotation_x_matrix, 0.015))
			exit_app(map, 2);
	if (key == KEY_UP)
		if (!rotate_camera(map, &rotation_y_matrix, -0.015))
			exit_app(map, 2);
	if (key == KEY_DOWN)
		if (!rotate_camera(map, &rotation_y_matrix, 0.015))
			exit_app(map, 2);
	if (key == 'k')
		if (!rotate_camera(map, &rotation_z_matrix, -0.015))
			exit_app(map, 2);
	if (key == 'l')
		if (!rotate_camera(map, &rotation_z_matrix, 0.015))
			exit_app(map, 2);
	if (key == ESCAPE_KEY)
		exit_app(map, 0);
}

int	deal_key(int key, void *param)
{
	t_fdf *map;

	map = param;
	if (key == 'a')
		map->cam->position->tab[0] = map->cam->position->tab[0] - map->cam->speed;
	if (key == 'd')
		map->cam->position->tab[0] = map->cam->position->tab[0] + map->cam->speed;
	if (key == 'w')
		map->cam->position->tab[1] = map->cam->position->tab[1] + map->cam->speed;
	if (key == 's')
		map->cam->position->tab[1] = map->cam->position->tab[1] - map->cam->speed;
	if (key == 'i')
		map->cam->position->tab[2] = map->cam->position->tab[2] + map->cam->speed;
	if (key == 'o')
		map->cam->position->tab[2] = map->cam->position->tab[2] - map->cam->speed;
	deal_key2(key, map);
	render_screen(map);
	return (1);
}
