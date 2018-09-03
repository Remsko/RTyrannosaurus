/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_divide_const.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:00:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 16:11:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    color_divide_const(t_color divident, const Uint8 divisor)
{
    divident.r /= divisor;
    divident.g /= divisor;
    divident.b /= divisor;
}