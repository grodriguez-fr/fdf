/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:38:29 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 11:38:12 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	memory_overlap(void *dst, const void *src, size_t len)
{
	if ((src >= dst) && (src <= dst + len))
		return (1);
	if ((src <= dst) && ((src + len) >= dst))
		return (1);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src)
		return (dst);
	if (!memory_overlap(dst, src, len))
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		i = 1;
		while (i - 1 < len)
		{
			((unsigned char *)dst)[len - i] = ((unsigned char *)src)[len - i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}
