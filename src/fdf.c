#include "fdf.h"

void	render_screen(t_fdf *map)
{
	map->img.img = mlx_new_image(map->mlx, SCREEN_W, SCREEN_H);
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, \
			&map->img.line_length, &map->img.endian);
	draw_map(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	mlx_destroy_image(map->mlx, map->img.img);
}

int	init_map(t_fdf **map, char *arg)
{
	float	max;
	int	ret;

	(*map) = malloc(sizeof(t_fdf));
	if (!(*map))
		exit(0);
	(*map)->cam = 0;
	ret = parse_map(*map, arg);
	if(ret != 1)
		exit_app(*map, ret);
	(*map)->mlx= mlx_init();
	(*map)->win= mlx_new_window((*map)->mlx, SCREEN_W, SCREEN_H, "FdF");
	(*map)->cam = malloc(sizeof(t_camera));
	if (!(*map)->cam)
		exit_app(*map, 2);
	max = (float)(*map)->dimx;
	if ((*map)->dimy > (*map)->dimx)
		max = (float)(*map)->dimy;
	if (!init_cam((*map)->cam, 27/19.0*max, 27/19.0*max, -30/19.0*max, max/25))
		exit_app(*map, 2);
	return (1);
}
