/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 12:52:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    sdl_draw(t_env *e, t_visu *v)
{
	SDL_RenderClear(v->renderer);
	raytracer_core(e, v);
	SDL_RenderPresent(v->renderer);
}
