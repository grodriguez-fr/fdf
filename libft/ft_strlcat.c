/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:34:53 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/12 12:09:17 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	lensrc;

	i = 0;
	len = 0;
	while (dst && dst[len] && len < size)
		len++;
	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	if (len > size || (size == 0 && !dst))
		return (size + lensrc);
	while (src[i] != '\0' && size && len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len < size)
		dst[len + i] = '\0';
	return (len + lensrc);
}
