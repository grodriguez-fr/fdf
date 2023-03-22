/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:43:34 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/09 11:44:48 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}
