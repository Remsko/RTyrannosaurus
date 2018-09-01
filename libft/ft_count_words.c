/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:00:41 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/07 13:57:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	int	count;
	int	get_count;

	count = 0;
	get_count = 0;
	while (*s != '\0')
	{
		if (get_count == 1 && *s == c)
			get_count = 0;
		if (get_count == 0 && *s != c)
		{
			get_count = 1;
			++count;
		}
		++s;
	}
	return (count);
}
