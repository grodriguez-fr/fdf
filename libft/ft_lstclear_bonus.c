/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:17:43 by gurodrig          #+#    #+#             */
/*   Updated: 2022/11/11 13:17:44 by gurodrig         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*buffer;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current && lst)
	{
		buffer = current->next;
		ft_lstdelone(current, del);
		current = buffer;
	}
	*lst = NULL;
}
