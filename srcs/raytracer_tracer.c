/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_tracer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:03:15 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 10:17:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color  throw_ray(t_ray *ray, int rebound)
{
    t_color color;

    ft_bzero(&color, sizeof(t_color));
    (void)ray;
    (void)rebound;
    return (color);
}

void raytracer_tracer(t_env *e, t_visu *v, t_color *c, int x, int y)
{
    t_ray   ray;
    t_color new_color;
    double  new_x;
    double  new_y;
    int     row;
    int     col;

    row = 0;
    while (row < e->samples)
    {
        col = 0;
        while (col < e->samples)
        {
            ft_bzero(&new_color, sizeof(t_color));
            new_x = (double)(x + v->screen.width / 2 + (col + 0.5) / e->samples);
            new_y = (double)(v->screen.height / 2 - y + (row + 0.5) / e->samples);
            ray = new_ray(e->camera, new_x, new_y);
            new_color = throw_ray(&ray, e->rebound);
            color_add(*c, new_color);
            ++col;
        }
        ++row;
    }
    color_divide_const(*c, (const Uint8)e->samples * e->samples);
}