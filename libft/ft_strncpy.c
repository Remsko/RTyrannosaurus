/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:03:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/07 13:46:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *str;

	str = dest;
	while (n && *src)
	{
		*str++ = *src++;
		--n;
	}
	*str = '\0';
	while (n--)
		*str++ = '\0';
	return (dest);
}
