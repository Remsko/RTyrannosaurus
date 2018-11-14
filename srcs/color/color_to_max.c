/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:05:57 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 10:00:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "math.h"

void color_to_max_255(t_color *color)
{
    color->r = fmin(color->r, 255.0);
    color->g = fmin(color->g, 255.0);
    color->b = fmin(color->b, 255.0);
}

void color_to_max_1(t_color *color)
{
    color->r = fmin(color->r, 1.0);
    color->g = fmin(color->g, 1.0);
    color->b = fmin(color->b, 1.0);
}