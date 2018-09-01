/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:33:56 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/17 15:40:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isstrint(char *str, int *target)
{
	char	*cmp;
	t_bool	ret;

	ret = TRUE;
	*target = ft_atoi(str);
	cmp = ft_itoa(*target);
	if (ft_strcmp(str, cmp) != 0)
		ret = FALSE;
	ft_strdel(&cmp);
	return (ret);
}
