/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:17:26 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 14:00:57 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	if (!content)
		new_elem->content = NULL;
	else
	{
		new_elem->content = content;
		if (!new_elem->content)
		{
			free(new_elem);
			return (NULL);
		}
	}
	new_elem->next = NULL;
	return (new_elem);
}
