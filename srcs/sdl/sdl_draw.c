/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:58:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_draw(t_env *e, t_visu *v)
{
	(void)e;
	SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderClear(v->renderer);
	SDL_RenderPresent(v->renderer);
}
