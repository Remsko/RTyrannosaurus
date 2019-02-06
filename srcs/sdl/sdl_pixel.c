/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:55:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 13:30:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"

#include "color.h"
#include "visu.h"

void sdl_pixel(const t_visu *v, const t_color *c, const int x, const int y)
{
    SDL_SetRenderDrawColor(v->renderer, (Uint8)c->r, (Uint8)c->g, (Uint8)c->b, 255);
    SDL_RenderDrawPoint(v->renderer, x, y);
}