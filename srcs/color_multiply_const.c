/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multiply_const.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:06:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 17:59:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    color_multiply_const(t_color *target, const double amount)
{
    target->r *= amount;
    target->g *= amount;
    target->b *= amount;
}