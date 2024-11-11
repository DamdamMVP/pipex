/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:25:48 by dalebran          #+#    #+#             */
/*   Updated: 2023/10/19 13:21:34 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	t_list	*current;

	new_head = NULL;
	new_node = NULL;
	current = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node || !f)
		{
			if (new_head)
				ft_lstclear(&new_head, del);
			return (NULL);
		}
		if (!current)
			new_head = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (new_head);
}
