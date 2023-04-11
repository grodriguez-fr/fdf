#include "fdf.h"

void	init_draw(t_draw *d, t_fdf *map)
{
	init_mat4(&d->projection);
	init_mat4(&d->cammat);
	init_mat4(&d->screen);
	init_vec4(&d->res);
	init_vec4(&d->res2);
	projection_matrix(map->cam, d->projection);
	camera_matrix(map->cam, d->cammat);
	camera_screen_matrix(d->screen);
}

void	draw_map(t_fdf *map)
{
	t_draw		d;
	unsigned int	i;
	unsigned int	j;

	init_draw(&d, map);
	i = 0;
	while (i < map->dimy)
	{
		j = 0;
		while (j < map->dimx)
		{
			proj_vec(d.projection, d.cammat, d.screen, &map->map[i][j], d.res);
			printf("%f : %f\n", d.res->tab[0], d.res->tab[1]);	
			mlx_pixel_put(map->mlx, map->win, d.res->tab[0], d.res->tab[1], 0x00FFFFFF);
			if (i + 1 < map->dimy)
			{
				proj_vec(d.projection, d.cammat, d.screen, &map->map[i + 1][j], d.res2);
				printf("ligne entre : ");	
				printvec(d.res);
				printf(" et ");	
				printvec(d.res2);
				printf("\n");	
				draw_line(map, d.res, d.res2);	
			}
			if (j + 1 < map->dimx)
			{
				proj_vec(d.projection, d.cammat, d.screen, &map->map[i][j + 1], d.res2);
				printf("ligne entre : ");	
				printvec(d.res);
				printf(" et ");	
				printvec(d.res2);
				printf("\n");	
				draw_line(map, d.res, d.res2);	
			}
			j++;
		}
		i++;	
	}
}
