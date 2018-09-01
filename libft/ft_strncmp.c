/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 11:35:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (unsigned char)*s1++ == (unsigned char)*s2++ && (*s1 || *s2))
		--n;
	return (int)(n == 0 ? 0 : (unsigned char)*(--s1) - (unsigned char)*(--s2));
}
