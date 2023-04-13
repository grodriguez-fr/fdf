#include "fdf.h"

void	free_map(t_fdf *map)
{
	unsigned int	i;
	unsigned int	j;

	if (!map->map)
		return ;
	i = 0;
	while (i < map->dimy)
	{
		j = 0;
		while (map->map[i] && j < map->dimx)
		{
			free(map->map[i][j].tab);
			j++;
		}
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int	exit_app(t_fdf *map)
{
	printf("exiiit app\n");
	if (!map)
		return (exit(0), 1);
	free_map(map);
	free_cam(map->cam);
	if (map->mlx && map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map);
	return (exit(0), 1);
}

void	free_splited(char **splited)
{
	int	i;

	if (!*splited)
		return ;
	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
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
