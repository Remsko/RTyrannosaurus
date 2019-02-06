/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jittered_sample.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:12:23 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 21:40:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "visu.h"

static double r(void)
{
    return ((rand() % 10) / 10.0);
}

t_position jittered_sample(t_screen *screen, t_pixel *pixel, int row, int column, int samples)
{
    t_position position;

    position.x = pixel->x - screen->width * 0.5 + (column + r()) / samples;
    position.y = screen->height * 0.5 - pixel->y + (row + r()) / samples;
    return (position);
}