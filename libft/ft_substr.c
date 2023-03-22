/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:48 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/09 17:39:48 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_new;
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	len_new = 0;
	while (start < ft_strlen(s) && s[start + len_new] && len_new < len)
		len_new++;
	res = (char *)malloc(sizeof(char) * (len_new + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len_new)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
