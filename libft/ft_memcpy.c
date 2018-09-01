/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:14:20 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 11:14:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	ret = dst;
	while (n)
	{
		*(unsigned char*)dst++ = *(const unsigned char *)src++;
		--n;
	}
	return (ret);
}
