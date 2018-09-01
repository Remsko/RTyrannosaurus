/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/01 14:27:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    sdl_draw(t_visu *v)
{
	SDL_RenderClear(v->renderer);
	SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderPresent(v->renderer);
}
