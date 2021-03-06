/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:42:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/04 17:30:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "visu.h"

/*
** Capture keyboard events
*/

void	sdl_event(t_events *e)
{
	SDL_Event   event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			e->options.exit = 1;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			e->options.exit = 1;
		else
			e->keys = SDL_GetKeyboardState(NULL);
	}
}
