#include "fdf.h"

void	translation_matrix(t_mat4 *m, float tx, float ty, float tz)
{
	m->tab[0][0] = 1;
	m->tab[0][1] = 0;
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = 1;
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = 0;
	m->tab[2][2] = 1;
	m->tab[2][3] = 0;
	m->tab[3][0] = tx;
	m->tab[3][1] = ty;
	m->tab[3][2] = tz;
	m->tab[3][3] = 1;
}

void	scaling_matrix(t_mat4 *m, float scale)
{
	m->tab[0][0] = scale;
	m->tab[0][1] = 0;
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = scale;
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = 0;
	m->tab[2][2] = scale;
	m->tab[2][3] = 0;
	m->tab[3][0] = 0;
	m->tab[3][1] = 0;
	m->tab[3][2] = 0;
	m->tab[3][3] = 1;
}

/*add rotation matrix*/
