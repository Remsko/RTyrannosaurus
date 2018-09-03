/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:43:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 13:15:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    raytracer_core(t_env *e, t_visu *v)
{
    t_color color;
    Uint8 a;
    int x;
    int y;

    a = 255;
    y = 0;
    while (y < v->screen.height)
    {
        x = 0;
        while (x < v->screen.width)
        {
            ft_bzero(&color, sizeof(t_color));
            raytracer_tracer(e, v, &color, x, y);
            SDL_SetRenderDrawColor(v->renderer, color.r, color.g, color.b, a);
		    SDL_RenderDrawPoint(v->renderer, x, y);
            ++x;
        }
        ++y;
    }
}