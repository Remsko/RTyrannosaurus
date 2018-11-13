/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:03:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 20:47:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void    color_divide(t_color *target, t_color *amount)
{
    target->r /= amount->r;
    target->g /= amount->g;
    target->b /= amount->b;
}

void    color_divide_const(t_color *target, const double amount)
{
    target->r /= amount;
    target->g /= amount;
    target->b /= amount;
}

t_color color_divide_ret(t_color *color, t_color *amount)
{
    t_color ret;

    ret.r = color->r / amount->r;
    ret.g = color->g / amount->g;
    ret.b = color->b / amount->b;
    return (ret);
}

t_color color_divide_const_ret(t_color *color, const double amount)
{
    t_color ret;

    ret.r = color->r / amount;
    ret.g = color->g / amount;
    ret.b = color->b / amount;
    return (ret);
}