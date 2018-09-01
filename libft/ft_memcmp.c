/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:07:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 11:21:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;

	s1_tmp = (const unsigned char*)s1;
	s2_tmp = (const unsigned char*)s2;
	while (n)
	{
		if (*s1_tmp != *s2_tmp)
			return (*s1_tmp - *s2_tmp);
		++s1_tmp;
		++s2_tmp;
		--n;
	}
	return (0);
}
