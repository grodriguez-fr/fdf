/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:27:32 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 13:35:32 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			return ((char *)&s[i - 1]);
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}
