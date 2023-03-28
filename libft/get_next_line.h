/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:14:21 by gurodrig          #+#    #+#             */
/*   Updated: 2023/03/28 11:27:02 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif // BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif // GET_NEXT_LINE_H
