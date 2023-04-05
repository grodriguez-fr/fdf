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
			if (i + 1 < map->dimx)
			{
				proj_vec(d.projection, d.cammat, d.screen, &map->map[i + 1][j], d.res2);
				draw_line(map, d.res, d.res2);	
			}
			if (j + 1 < map->dimy)
			{
				proj_vec(d.projection, d.cammat, d.screen, &map->map[i][j + 1], d.res2);
				draw_line(map, d.res, d.res2);	
			}
			j++;
		}
		i++;	
	}
}

void	draw_line(t_fdf *map, t_vector4 *start, t_vector4 *end)
{
	t_bresenham b;

	b.dy = (int)end->tab[1] - (int)start->tab[1];
	b.dx = (int)end->tab[0] - (int)start->tab[0];
	b.y = (int)start->tab[1];
	b.e = 0;
	printf("%d avant :\n", b.dx);
	b.e10 = b.dy / b.dx;
	printf("apres\n");
	b.e01 = -1;
	b.x = start->tab[0];
	while (b.x <= end->tab[0])
	{
		mlx_pixel_put(map->mlx, map->win, b.x, b.y, 0xFFFFFF);
		b.e += b.e10;
		if (b.e	>= 0.5)
		{
			b.y += 1;
			b.e += b.e01;	
		}
		b.x++;
	}
}
