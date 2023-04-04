#include "fdf.h"

static int	init_vec4(t_vector4 **vec)
{
	int i;

	*vec = malloc(sizeof(t_vector4));
	if (!*vec)
		return (0);
	(*vec)->tab = malloc(sizeof(float) * 4);
	if (!(*vec)->tab)
		return (free(vec), 0);
	i = 0;
	while (i < 3)
		(*vec)->tab[i++] = 0;
	(*vec)->tab[i] = 1;
	return (1);
}

static void	free_v(t_vector4 *vec)
{
	free(vec->tab);
	free(vec);
}
#include <stdio.h>
int	init_cam(t_camera *c, float x, float y, float z)
{
	if (!init_vec4(&c->position))
		return (0);
	if (!init_vec4(&c->forward))
		return (free_v(c->position), 0);
	if (!init_vec4(&c->up))
		return (free_v(c->position), free_v(c->forward), 0);
	if (!init_vec4(&c->right))
		return (free_v(c->position), free_v(c->forward), free_v(c->up), 0);
	printf("lai\n");
	c->position->tab[0] = x;
	printf("la\n");
	c->position->tab[1] = y;
	printf("la\n");
	c->position->tab[2] = z;
	printf("la\n");
	c->forward->tab[2] = 1;
	c->up->tab[1] = 1;
	c->right->tab[2] = 1;
	c->h_fov = M_PI / 3;
	c->v_fov = c->h_fov * (SCREEN_H / SCREEN_W);
	c->near_plane = 0.1;
	c->far_plane = 100;
	return (1);
}

void	free_cam(t_camera *cam)
{
	free_v(cam->position);
	free_v(cam->forward);
	free_v(cam->up);
	free_v(cam->right);
	free(cam);
}
