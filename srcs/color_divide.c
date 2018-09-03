/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:03:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 16:06:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    color_divide(t_color divident, t_color divisor)
{
    divident.r /= divisor.r;
    divident.g /= divisor.g;
    divident.b /= divisor.b;
}