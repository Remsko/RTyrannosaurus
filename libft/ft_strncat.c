/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:28:56 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 11:59:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *str;

	str = dest;
	while (*str)
		++str;
	while (n && (*str++ = *src++))
		--n;
	n <= 0 ? *str = '\0' : 0;
	return (dest);
}
