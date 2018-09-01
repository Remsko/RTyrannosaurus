/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:28:34 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/13 13:41:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int tmp_nb;

	if (n < 0)
	{
		ft_putchar('-');
		tmp_nb = -n;
	}
	else
		tmp_nb = n;
	if (tmp_nb > 9)
	{
		ft_putnbr(tmp_nb / 10);
		ft_putnbr(tmp_nb % 10);
	}
	else
		ft_putchar(tmp_nb + '0');
}
