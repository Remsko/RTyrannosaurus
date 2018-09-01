/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:57:13 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 15:29:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new;

	head = NULL;
	if (lst && f)
	{
		head = (*f)(lst);
		new = head;
		while (lst->next)
		{
			new->next = (*f)(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (head);
}
