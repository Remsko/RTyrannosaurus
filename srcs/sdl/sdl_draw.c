/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:01 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 20:09:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "visu.h"

/*
** Launch and display rendering
*/

void    sdl_draw(t_scene *s, t_visu *v)
{
	SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderClear(v->renderer);
	raytracer(s, v);
	SDL_RenderPresent(v->renderer);
}
