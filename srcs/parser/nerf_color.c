/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nerf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:28:21 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 17:34:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parser.h"

void nerf_color(t_color *color)
{
    nerf_double(&color->r, 0.0, 255.0);
    nerf_double(&color->g, 0.0, 255.0);
    nerf_double(&color->b, 0.0, 255.0);
}