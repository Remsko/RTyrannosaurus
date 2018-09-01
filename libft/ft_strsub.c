/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:59:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 13:16:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ret;

	if (!s || !(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	ret = str;
	s += start;
	while (len--)
		*str++ = *(char *)s++;
	*str = '\0';
	return (ret);
}
