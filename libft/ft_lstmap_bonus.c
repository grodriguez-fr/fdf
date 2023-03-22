/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:17:15 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 17:48:39 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*res;

	if (!f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		if (!current)
		{
			while (!res)
			{
				current = res->next;
				(*del)(res->content);
				free(res);
				res = current;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&res, current);
		lst = lst->next;
	}
	return (res);
}
