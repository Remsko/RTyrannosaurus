/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remsko <remsko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:46:51 by remsko            #+#    #+#             */
/*   Updated: 2018/05/11 15:20:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alist)
{
	t_list	*next;
	t_list	*previous;

	previous = NULL;
	while (*alist != NULL)
	{
		next = (*alist)->next;
		(*alist)->next = previous;
		previous = (*alist);
		*alist = next;
	}
	*alist = previous;
}
