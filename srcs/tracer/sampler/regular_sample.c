/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_sample.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:29:04 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 21:41:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "visu.h"

t_position regular_sample(t_screen *screen, t_pixel *pixel, int row, int column, int samples)
{
    t_position position;

    position.x = pixel->x - screen->width * 0.5 + (column + 0.5) / samples;
    position.y = screen->height * 0.5 - pixel->y + (row + 0.5) / samples;
    return (position);
}