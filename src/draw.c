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

void	init_bresenham(t_bresenham *b, int x0, int y0, int x1, int y1) 
{
	b->dx = x1 - x0;
	b->dy = y1 - y0;
	b->x = x0;
	b->y = y0;
	b->p = 2 * b->dy - b->dx;
}

void	draw_line(t_fdf *map, t_vector4 *start, t_vector4 *end)
{
	t_bresenham b;

	init_bresenham(&b, start->tab[0], start->tab[1], end->tab[0], end->tab[1]);
	while(b.x < (int)end->tab[0])
	{
		if (b.p >= 0)
		{
			mlx_pixel_put(map->mlx, map->win, b.x, b.y, 0x00FFFFFF);
			b.y = b.y + 1;
			b.p = b.p + 2 * b.dy - 2 * b.dx;		
		}
		else
		{
			mlx_pixel_put(map->mlx, map->win, b.x, b.y, 0x00FFFFFF);
			b.p = b.p + 2 * b.dy;	
		}
		b.x = b.x + 1;
	}
}
