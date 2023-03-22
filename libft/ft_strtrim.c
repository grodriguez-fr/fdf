/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:00 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/12 12:21:01 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	char_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	start;
	int				end;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && char_in_set(set, s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > 0 && char_in_set(set, s[end]))
		end--;
	return (ft_substr(s, start, end - start + 1));
}
