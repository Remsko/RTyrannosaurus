/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:21:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/07 13:45:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ft_strncpy(ret, s, n));
}
