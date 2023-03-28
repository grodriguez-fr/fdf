/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:10:35 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 12:21:43 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr_gnl(char *src, char searched)
{
	size_t	i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		if (src[i++] == searched)
			return (&src[i - 1]);
	return (NULL);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	unsigned int	lnew;
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	lnew = 0;
	while (start < (unsigned)ft_strlen_gnl(s) && s[start + lnew] && lnew < len)
		lnew++;
	res = (char *)malloc(sizeof(char) * (lnew + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < lnew)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
