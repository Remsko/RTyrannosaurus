#include "rt.h"

void	sdl_event(t_events *e)
{
	SDL_Event   event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			e->options.exit = TRUE;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			e->options.exit = TRUE;
		else
			e->keys = SDL_GetKeyboardState(NULL);
	}
}