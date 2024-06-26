/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:54:42 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 12:54:44 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	camera_translate_matrix(t_camera *cam, t_mat4 *res)
{
	res->tab[0][0] = 1;
	res->tab[0][1] = 0;
	res->tab[0][2] = 0;
	res->tab[0][3] = 0;
	res->tab[1][0] = 0;
	res->tab[1][1] = 1;
	res->tab[1][2] = 0;
	res->tab[1][3] = 0;
	res->tab[2][0] = 0;
	res->tab[2][1] = 0;
	res->tab[2][2] = 1;
	res->tab[2][3] = 0;
	res->tab[3][0] = -cam->position->tab[0];
	res->tab[3][1] = -cam->position->tab[1];
	res->tab[3][2] = -cam->position->tab[2];
	res->tab[3][3] = 1;
}

void	camera_rotate_matrix(t_camera *cam, t_mat4 *res)
{
	res->tab[0][0] = cam->right->tab[0];
	res->tab[0][1] = cam->up->tab[0];
	res->tab[0][2] = cam->forward->tab[0];
	res->tab[0][3] = 0;
	res->tab[1][0] = cam->right->tab[1];
	res->tab[1][1] = cam->up->tab[1];
	res->tab[1][2] = cam->forward->tab[1];
	res->tab[1][3] = 0;
	res->tab[2][0] = cam->right->tab[2];
	res->tab[2][1] = cam->up->tab[2];
	res->tab[2][2] = cam->forward->tab[2];
	res->tab[2][3] = 0;
	res->tab[3][0] = 0;
	res->tab[3][1] = 0;
	res->tab[3][2] = 0;
	res->tab[3][3] = 1;
}

int	camera_matrix(t_camera *cam, t_mat4 *res)
{
	t_mat4	*translate;
	t_mat4	*rotate;

	if (!init_mat4(&translate))
		return (0);
	if (!init_mat4(&rotate))
		return (free_mat4(translate), 0);
	camera_translate_matrix(cam, translate);
	camera_rotate_matrix(cam, rotate);
	mult(translate, rotate, res);
	free_mat4(translate);
	free_mat4(rotate);
	return (1);
}

void	projection_matrix(t_camera *cam, t_mat4 *res)
{
	float	far;
	float	near;

	far = cam->far_plane;
	near = cam->near_plane;
	res->tab[0][0] = 2 / (tan(cam->h_fov / 2) * 2);
	res->tab[0][1] = 0;
	res->tab[0][2] = 0;
	res->tab[0][3] = 0;
	res->tab[1][0] = 0;
	res->tab[1][1] = 2 / (tan(cam->v_fov / 2) * 2);
	res->tab[1][2] = 0;
	res->tab[1][3] = 0;
	res->tab[2][0] = 0;
	res->tab[2][1] = 0;
	res->tab[2][2] = (far + near) / (far - near);
	res->tab[2][3] = 1;
	res->tab[3][0] = 0;
	res->tab[3][1] = 0;
	res->tab[3][2] = -2 * far * near / (far - near);
	res->tab[3][3] = 0;
}

void	camera_screen_matrix(t_mat4 *res)
{
	res->tab[0][0] = SCREEN_W / 2;
	res->tab[0][1] = 0;
	res->tab[0][2] = 0;
	res->tab[0][3] = 0;
	res->tab[1][0] = 0;
	res->tab[1][1] = -SCREEN_H / 2;
	res->tab[1][2] = 0;
	res->tab[1][3] = 0;
	res->tab[2][0] = 0;
	res->tab[2][1] = 0;
	res->tab[2][2] = 1;
	res->tab[2][3] = 0;
	res->tab[3][0] = SCREEN_W / 2;
	res->tab[3][1] = SCREEN_H / 2;
	res->tab[3][2] = 0;
	res->tab[3][3] = 1;
}
