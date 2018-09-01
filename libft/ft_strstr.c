/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:53:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 14:01:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char const *h;
	char const *n;

	if (*needle == '\0')
		return (char *)(haystack);
	while (*haystack)
	{
		if (*needle == *haystack)
		{
			h = haystack + 1;
			n = needle + 1;
			while (*n && *n == *h)
			{
				++h;
				++n;
			}
			if (*n == '\0')
				return (char *)(haystack);
		}
		++haystack;
	}
	return (NULL);
}
