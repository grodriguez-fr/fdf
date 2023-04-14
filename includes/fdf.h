/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:20:53 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 15:21:23 by gurodrig         ###   ########.fr       */
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
# define SCREEN_W 1000

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define ESCAPE_KEY 65307

# define NEAR_PLANE 0.1f
# define FAR_PLANE 100

typedef struct s_bresenham
{
	int	p0x;
	int	p0y;
	int	p1x;
	int	p1y;
}	t_bresenham;

typedef struct s_vector4
{
	float	*tab;
}	t_vector4;

typedef struct s_mat4
{
	float	**tab;
}	t_mat4;

typedef struct s_draw
{
	unsigned int	i;
	unsigned int	j;
	t_mat4			*projection;
	t_mat4			*screen;	
	t_mat4			*cammat;
	t_vector4		*res;
	t_vector4		*res2;
}	t_draw;

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
	float		speed;
}	t_camera;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	t_vector4		**map;
	t_camera		*cam;
	t_img			img;
	unsigned int	dimx;
	unsigned int	dimy;
	void			*mlx;
	void			*win;
}	t_fdf;

/*main functions */
int		deal_key(int key, void *param);
int		exit_app(t_fdf *map, int error);
int		exitmlx(void *arg);
int		init_map(t_fdf **map, char *arg);

/* parsing */
int		parse_map(t_fdf *map, const char *filename);
int		write_error(void);
int		numbers_per_line(char *line);
int		init_cam(t_camera *cam, float xy, float z, float speed);
void	free_splited(char **splited);

/* draw and camera functions */
void	free_cam(t_camera *cam);
void	draw_map(t_fdf *map);
void	draw_line(t_fdf *map, t_vector4 *start, t_vector4 *end);
void	my_mlx_put_pixel(t_fdf *map, int x, int y);
void	render_screen(t_fdf *map);
int		rotate_camera(t_fdf *map, void (*rot_fun) (t_mat4 *, float), float a);

/* vector and matrix functions*/
int		init_mat4(t_mat4 **m);
int		init_vec4(t_vector4 **vec);
void	free_mat4(t_mat4 *m);
void	free_v(t_vector4 *vec);

void	translation_matrix(t_mat4 *m, float tx, float ty, float tz);
void	scaling_matrix(t_mat4 *m, float scale);
void	rotation_x_matrix(t_mat4 *m, float a);
void	rotation_y_matrix(t_mat4 *m, float a);
void	rotation_z_matrix(t_mat4 *m, float a);
int		camera_matrix(t_camera *cam, t_mat4 *res);
void	projection_matrix(t_camera *cam, t_mat4 *res);
void	camera_screen_matrix(t_mat4 *res);

int		proj_vec(t_draw *d, t_vector4 *e, t_vector4 *s);
void	set_vector(t_fdf *map, int nb, int i, int j);
void	vec_copy(t_vector4 *dst, t_vector4 *src);
void	mult(t_mat4 *a, t_mat4 *b, t_mat4 *res);
void	multvec(t_vector4 *a, t_mat4 *b, t_vector4 *res);

#endif
