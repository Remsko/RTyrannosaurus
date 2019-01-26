/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:01 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 18:19:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

/*
** Launch and display rendering
*/

void    sdl_draw(t_scene *s, t_visu *v)
{
	(void)s;
	SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderClear(v->renderer);
	SDL_RenderPresent(v->renderer);
}
