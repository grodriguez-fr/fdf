#include "fdf.h"

static void	draw_line_higrad(t_bresenham *b, t_fdf *map)
{
	int			delta[2];
	int			way_x;
	int			error;

	printf("higrad\n");
	delta[0] = b->p1x - b->p0x;
	delta[1] = b->p1y - b->p0y;
	way_x = 1;
	if (delta[0] < 0 && (delta[0] *= -1))
		way_x = -1;
	error = 2 * delta[0] - delta[1];
	while (b->p0y < b->p1y)
	{
		mlx_pixel_put(map->mlx, map->win, b->p0x, b->p0y, 0x00FFFFFF);
		//img[(p0.y * win_w + p0.x)] = color;
		if (error > 0)
		{
			b->p0x = b->p0x + way_x;
			error -= 2 * delta[1];
		}
		error += 2 * delta[0];
		b->p0y = b->p0y + 1;
	}
}

static void	draw_line_lograd(t_bresenham *b, t_fdf *map)
{
	int			delta[2];
	int			way_y;
	int			error;

	printf("lograd\n");
	delta[0] = b->p1x - b->p0x;
	delta[1] = b->p1y - b->p0y;
	way_y = 1;
	if (delta[1] < 0 && (delta[1] *= -1))
		way_y = -1;
	error = 2 * delta[1] - delta[0];
	while (b->p0x < b->p1x)
	{
		mlx_pixel_put(map->mlx, map->win, b->p0x, b->p0y, 0x00FFFFFF);
		//img[(p0.y * win_w + p0.x)] = color;
		if (error > 0)
		{
			b->p0y = b->p0y + way_y;
			error -= 2 * delta[0];
		}
		error += 2 * delta[1];
		b->p0x = b->p0x + 1;
	}
}

void	init_bresenham(t_bresenham *b, int x0, int y0, int x1, int y1) 
{
	b->p0x = x0;
	b->p0y = y0;
	b->p1x = x1;
	b->p1y = y1;
}

void	exchange_p0_p1(t_bresenham *b)
{
	int	bufferx;
	int	buffery;
	
	bufferx = b->p0x;
	buffery = b->p0y;
	b->p0x = b->p1x;
	b->p0y = b->p1y;
	b->p1x = bufferx;
	b->p1y = buffery;
}

void	draw_line(t_fdf *map, t_vector4 *start, t_vector4 *end)
{
	t_bresenham b;

	init_bresenham(&b, start->tab[0], start->tab[1], end->tab[0], end->tab[1]);
	if (abs(b.p1y - b.p0y) < abs(b.p1x - b.p0x))
	{
		if (b.p0x > b.p1x)
			exchange_p0_p1(&b);
		draw_line_lograd(&b, map);
	}
	else
	{
		if (b.p0y > b.p1y)
			exchange_p0_p1(&b);
		draw_line_higrad(&b, map);
	}
}
