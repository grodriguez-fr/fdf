/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:17 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 17:56:37 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_itoa_len(unsigned int nb, int unsigned *i)
{
	while (nb >= 10)
	{
		nb /= 10;
		*i = *i + 1;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	i;
	char			*res;

	i = 1;
	nb = (unsigned int)n;
	if (n < 0)
	{
		nb = ((unsigned int) n) * -1;
		i = 2;
	}
	ft_itoa_len(nb, &i);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i--] = 0;
	while (nb >= 10)
	{
		res[i--] = nb % 10 + 48;
		nb /= 10;
	}
	res[i] = nb + 48;
	if (n < 0)
		res[0] = '-';
	return (res);
}
