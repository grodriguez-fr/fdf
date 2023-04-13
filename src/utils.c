#include "fdf.h"

int	write_error(void)
{
	ft_putstr_fd("Error while opening file : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	numbers_per_line(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		if (line[i] && line[i] != '\n')
			nb++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (nb);
}

void	set_vector(t_fdf *map, int nb, int i, int j)
{
	map->map[i][j].tab[0] = (float)i;
	map->map[i][j].tab[1] = (float)j;
	map->map[i][j].tab[2] = (float)nb/-10;
	map->map[i][j].tab[3] = 1;
}
