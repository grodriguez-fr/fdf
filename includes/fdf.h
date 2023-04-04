/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:20:53 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 11:28:29 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

# define SCREEN_H 500
# define SCREEN_W 500

typedef struct s_vector4
{
	float	*tab;
}	t_vector4;

typedef struct s_mat4
{
	float	**tab;
}	t_mat4;

typedef struct s_camera
{
	t_vector4	*position;
	t_vector4	*forward;
	t_vector4	*up;
	t_vector4	*right;
	float		h_fov;
	float		v_fov;
	float		near_plane;
	float		far_plane;
}	t_camera;

typedef struct s_fdf
{
	t_vector4	**map;
	t_camera	*cam;
	unsigned int	dimx;
	unsigned int	dimy;
	void		*mlx;
	void		*win;
}	t_fdf;


int		parse_map(t_fdf *map, const char *filename);
int		write_error(void);
int		numbers_per_line(char *line);
int		init_cam(t_camera *cam, float x, float y, float z);

void	free_cam(t_camera *cam);
void	set_vector(t_fdf *map, int nb, int i, int j);
void	translation_matrix(t_mat4 *m, float tx, float ty, float tz);
void	scaling_matrix(t_mat4 *m, float scale);
void	mult(t_mat4 *a, t_mat4 *b, t_mat4 *res);
void	camera_matrix(t_camera *cam, t_mat4 *res);
void	projection_matrix(t_camera *cam, t_mat4 *res);
void	camera_screen_matrix(t_mat4 *res);
void	proj_vec(t_mat4 *pr, t_mat4 *c, t_mat4 *sc, t_vector4 *e, t_vector4 *s);

#endif
