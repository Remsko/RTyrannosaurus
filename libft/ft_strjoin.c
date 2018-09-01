/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:10:57 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 11:21:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if (!(ret = (char*)malloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
