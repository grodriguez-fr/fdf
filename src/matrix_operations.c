#include "fdf.h"

void	mult(t_mat4 *a, t_mat4 *b, t_mat4 *res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res->tab[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				res->tab[i][j] += a->tab[i][k] * b->tab[k][j];
				k++;	
			}
			j++;	
		}
		i++;
	}
}

void	multvec(t_vector4 *a, t_mat4 *b, t_vector4 *res)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		res->tab[i] = 0;
		while (j < 4)
		{
			res->tab[i] += a->tab[j] * b->tab[j][i];
			j++;	
		}
		i++;
	}
}

void	normalize_vec(t_vector4 *vec)
{
	vec->tab[0] /= vec->tab[3];
	vec->tab[1] /= vec->tab[3];
	vec->tab[2] /= vec->tab[3];
	vec->tab[3] /= vec->tab[3];
	/*if (vec->tab[0] > 1 || vec->tab[0] < -1)
		vec->tab[0] = 0;
	if (vec->tab[1] > 1 || vec->tab[1] < -1)
		vec->tab[1] = 0;
	if (vec->tab[2] > 1 || vec->tab[2] < -1)
		vec->tab[2] = 0;*/
}

void	proj_vec(t_mat4 *pr, t_mat4 *c, t_mat4 *sc, t_vector4 *e, t_vector4 *s)
{
	t_vector4	*s2;

	printf("avant proj de :");
	printvec(e);
	printmat(c);
	init_vec4(&s2);
	multvec(e, c, s);
	printf("apres mult cam_mat :");
	printvec(s);
	printmat(pr);
	multvec(s, pr, s2);
	printf("apres matrice projection :");
	printvec(s2);
	normalize_vec(s2);
	printf("apres normalisation :");
	printvec(s2);
	multvec(s2, sc, s);
	printf("apres clipspace->screen :");
	printvec(s);
	free_v(s2);
}

