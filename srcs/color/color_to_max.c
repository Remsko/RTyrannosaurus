/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:05:57 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:09:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "math.h"

void color_to_max_255(t_color *color)
{
    color->r = fmax(color->r, 255.0);
    color->g = fmax(color->g, 255.0);
    color->b = fmax(color->b, 255.0);
}

void color_to_max_1(t_color *color)
{
    color->r = fmax(color->r, 1.0);
    color->g = fmax(color->g, 1.0);
    color->b = fmax(color->b, 1.0);
}