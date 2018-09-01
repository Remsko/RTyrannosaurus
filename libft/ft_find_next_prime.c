/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:45:21 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 18:54:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_prime(int nb)
{
	int nbr;

	nbr = 2;
	if (nb <= 1)
		return (0);
	while (nbr <= nb / nbr)
	{
		if (nb % nbr == 0)
			return (0);
		else
			nbr++;
	}
	return (1);
}

int			ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 0)
		return (ft_find_next_prime(nb + 1));
	else
		return (nb);
}
