/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jittered_sample.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:12:23 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 19:38:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "visu.h"

static double r(void)
{
    return ((rand() % 10) / 10.0);
}

t_pixel jittered_sample(t_screen *screen, int row, int column, int x, int y, int samples)
{
    t_pixel p;

    p.x = x - screen->width * 0.5 + (column + r()) / samples;
    p.y = screen->height * 0.5 - y + (row + r()) / samples;
    return (p);
}