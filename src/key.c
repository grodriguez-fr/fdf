#include "fdf.h"

int	exit_app(t_fdf *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->dimy)
	{
		j = 0;
		while (j < map->dimx)
		{
			free(map->map[i][j].tab);
			j++;
		}
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free_cam(map->cam);
	mlx_destroy_window(map->mlx, map->win);
	free(map);
	exit(0);
	return (1);
}

int	deal_key(int key, void *param)
{
	t_fdf *map;

	map = param;
	//printf("key : %d\n", key);
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
	if (key == ESCAPE_KEY)
		exit_app(map);
	render_screen(map);
	return (1);
}
