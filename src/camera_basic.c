#include "fdf.h"

void	init_iso(t_camera *c)
{
	c->up->tab[0] = -0.567347;
	c->up->tab[1] = -0.554885;
	c->up->tab[2] = -0.608447;
	c->right->tab[0] = -0.689570;
	c->right->tab[1] = 0.724022;
	c->right->tab[2] = -0.017296;
	c->forward->tab[0] = -0.450138;
	c->forward->tab[1] = -0.409766;
	c->forward->tab[2] = 0.793395;
}

int	init_cam(t_camera *c, float x, float y, float z, float speed)
{
	if (!init_vec4(&c->position))
		return (0);
	if (!init_vec4(&c->forward))
		return (free_v(c->position), 0);
	if (!init_vec4(&c->up))
		return (free_v(c->position), free_v(c->forward), 0);
	if (!init_vec4(&c->right))
		return (free_v(c->position), free_v(c->forward), free_v(c->up), 0);
	c->position->tab[0] = x;
	c->position->tab[1] = y;
	c->position->tab[2] = z;
	init_iso(c);
	c->h_fov = M_PI / 3;
	c->v_fov = c->h_fov * ((float)SCREEN_H / (float)SCREEN_W);
	c->near_plane = NEAR_PLANE;
	c->far_plane = FAR_PLANE;
	c->speed = speed;
	return (1);
}

void	free_cam(t_camera *cam)
{
	if (!cam)
		return ;
	free_v(cam->position);
	free_v(cam->forward);
	free_v(cam->up);
	free_v(cam->right);
	free(cam);
}

int	rotate_camera(t_fdf *map, void (*rotate_fun) (t_mat4 *, float), float a)
{
	t_mat4 *rot;
	t_vector4 *copy;

	return (0);
	if (!init_mat4(&rot))
		return (0);
	if (!init_vec4(&copy))
		return (free_mat4(rot), 0);
	rotate_fun(rot, a);
	vec_copy(copy, map->cam->up);
	multvec(copy, rot, map->cam->up);
	vec_copy(copy, map->cam->forward);
	multvec(copy, rot, map->cam->forward);
	vec_copy(copy, map->cam->right);
	multvec(copy, rot, map->cam->right);
	return (free_mat4(rot), free_v(copy), 1);
}
