/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:10:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 11:16:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len)
		{
			--len;
			*((unsigned char*)dst + len) = *((const unsigned char*)src + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
