/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:00:23 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 11:43:43 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*res;

	res = malloc(elementCount * elementSize);
	if (!res)
		return (NULL);
	ft_bzero(res, elementCount * elementSize);
	return (res);
}
