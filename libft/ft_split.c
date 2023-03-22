/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:49:16 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/09 15:34:17 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	lenmalloc(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count + 1);
}

static char	*word(const char *str, char c, int *j)
{
	int		i;
	char	*res;
	int		len;

	len = 0;
	while (str[*j] == c)
		*j += 1;
	while (str[*j + len] && str[*j + len] != c)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[*j + i] && str[*j + i] != c)
	{
		res[i] = str[*j + i];
		i++;
	}
	res[i] = 0;
	*j += i;
	return (res);
}

static void	ft_clean(char **strs, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
		free(strs[i++]);
	free(strs);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**res;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = lenmalloc(s, c);
	res = malloc(len * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (i < len - 1)
	{
		res[i] = word(s, c, &j);
		if (!res[i++])
		{
			ft_clean(res, i - 1);
			return (NULL);
		}
	}
	res[i] = 0;
	return (res);
}
