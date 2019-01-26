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
