/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:53:34 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/07 14:58:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(void *content, size_t content_size)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char**)content;
	(void)content_size;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}
