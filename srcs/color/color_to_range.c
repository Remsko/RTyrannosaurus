/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:00:32 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:05:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void color_to_range_0_255(t_color *color)
{
    color_multiply_const(color, 255.0);
}

void color_to_range_0_1(t_color *color)
{
    color_divide_const(color, 255.0);
}