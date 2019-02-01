/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nerf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:28:21 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/01 15:58:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parser.h"

void nerf_color(t_color *color)
{
    color_to_range_0_1(color);
    nerf_double(&color->r, 0.0, 1.0);
    nerf_double(&color->g, 0.0, 1.0);
    nerf_double(&color->b, 0.0, 1.0);
}