/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:41:59 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/23 15:14:08 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	add_to_memory(char **mem, char buffer[BUFFER_SIZE], int nb_read)
{
	char	*res;
	int		len_mem;
	int		i;
	int		j;

	len_mem = ft_strlen(*mem);
	res = (char *)malloc(sizeof(char) * (len_mem + nb_read + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (j < len_mem)
		res[i++] = (*mem)[j++];
	j = 0;
	while (j < nb_read)
		res[i++] = buffer[j++];
	res[i] = 0;
	if (*mem)
		free(*mem);
	*mem = res;
	return (1);
}

char	*get_line(char **mem)
{
	int		len;
	int		len2;
	char	*res;
	char	*buffer;

	len = 0;
	while ((*mem)[len] && (*mem)[len] != '\n')
		len++;
	if ((*mem)[len] == '\n')
		len++;
	res = ft_substr(*mem, 0, len);
	len2 = 0;
	while ((*mem)[len2])
		len2++;
	buffer = ft_substr(*mem, len, len2);
	free(*mem);
	*mem = buffer;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		buffer[BUFFER_SIZE];
	int			nb_read;

	if (ft_strchr(mem, '\n'))
		return (get_line(&mem));
	nb_read = read(fd, buffer, BUFFER_SIZE);
	while (nb_read > 0)
	{
		if (!add_to_memory(&mem, buffer, nb_read))
			return (NULL);
		if (ft_strchr(mem, '\n'))
			return (get_line(&mem));
		nb_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (mem && mem[0])
		return (get_line(&mem));
	if (mem)
		return (free(mem), NULL);
	return (NULL);
}
