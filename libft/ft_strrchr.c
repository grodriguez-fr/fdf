/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:30:53 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 13:35:38 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = NULL;
	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			res = (char *)&s[i - 1];
	if (s[i] == c)
		return ((char *)&s[i]);
	return (res);
}
