/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:49:56 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 16:50:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(ret, s));
}
