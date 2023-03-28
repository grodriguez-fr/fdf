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
# include "get_next_line.h"
# include "libft.h"

typedef struct s_fdf
{
	int				**map;
	unsigned int	dimx;
	unsigned int	dimy;
}	t_fdf;

typedef struct s_vector4
{
	int	*tab;
}	t_vector4;

typedef struct s_matrix4
{
	int	*t_vector4;	
}	t_matrix4;

int	parse_map(t_fdf *map, const char *filename);
#endif
