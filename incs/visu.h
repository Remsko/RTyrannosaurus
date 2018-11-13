#ifndef VISU_H
# define VISU_H

#include "SDL.H"

/*
** Graphic window structures to use SDL functions
*/

typedef struct	s_screen
{
	int			width;
	int			height;
} t_screen;

typedef struct	s_visu
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_screen		screen;
} t_visu;

/*
** Init SDL (visu sub-structures)
*/

void sdl_init(t_visu *v);


/*
** Free SDL (visu sub-structures)
*/

void sdl_destroy(t_visu *v);

/*
** Infinity loop to handle renders
*/

void sdl_loop(t_env *e, t_visu *v):

/*
** Draw in SDL_Renderer for rendering
*/

void sdl_draw(t_env *e, t_visu *v);

/*
** Capture keyboard events to interact
*/

void sdl_event(t_events *e)

#endif
