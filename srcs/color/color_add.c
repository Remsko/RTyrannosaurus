/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:03:48 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 13:19:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/*
** Compute addition on a color with a constant or an other color
** return a new color with pure function if necessary
*/

void color_add(t_color *target, t_color *amount)
{
    target->r += amount->r;
    target->g += amount->g;
    target->b += amount->b;
}

void color_add_const(t_color *target, const double amount)
{
    target->r += amount;
    target->g += amount;
    target->b += amount;
}

t_color color_add_ret(t_color *color, t_color *amount)
{
    t_color ret;

    ret.r = color->r + amount->r;
    ret.g = color->g + amount->g;
    ret.b = color->b + amount->b;
    return (ret);
}

t_color color_add_const_ret(t_color *color, const double amount)
{
    t_color ret;

    ret.r = color->r + amount;
    ret.g = color->g + amount;
    ret.b = color->b + amount;
    return (ret);
}