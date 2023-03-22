/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:20:53 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/22 16:43:57 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>

struct s_fdf 
{
	int			**map;
	unsigned int	dimx;
	unsigned int	dimy;
}	t_fdf;

struct s_vector4
{
	int	*tab;
}

struct s_matrix4
{
	int	*t_vector4;	
}	t_matrix4;

#endif
