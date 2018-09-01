/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:14:48 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned char	neg;
	int				nb;

	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' \
			|| *str == '\t' || *str == '\v')
		++str;
	neg = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		++str;
	}
	return (neg ? -nb : nb);
}
