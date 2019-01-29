/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:05:57 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 21:55:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"

/*
** Set rgb colors at a maximum value
*/

void color_to_max(t_color *color, const double maximum)
{
    color->r = fmin(color->r, maximum);
    color->g = fmin(color->g, maximum);
    color->b = fmin(color->b, maximum);
}

void color_to_max_255(t_color *color)
{
    color_to_max(color, 255.0);
}

void color_to_max_1(t_color *color)
{
    color_to_max(color, 1.0);
}