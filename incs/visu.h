#ifndef VISU_H
# define VISU_H

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

#endif
