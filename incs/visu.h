/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:26:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 22:38:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "SDL.h"
# include "scene.h"

/*
** Graphic window structures to use SDL functions
*/

typedef struct s_screen
{
	int width;
	int height;
} t_screen;

typedef struct s_options
{
	unsigned char exit : 1;
	unsigned char draw : 1;
	unsigned char fill : 6;
} t_options;

typedef struct s_events
{
	t_options options;
	const unsigned char *keys;
} t_events;

typedef struct s_visu
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	t_events events;
	t_screen screen;
} t_visu;

/*
** Init SDL (visu sub-structures)
** in sdl_init.c
*/

void sdl_init(t_visu *v);

/*
** Free SDL (visu sub-structures)
** in sdl_destroy.c
*/

void sdl_destroy(t_visu *v);

/*
** Infinity loop to handle renders
** in sdl_loop.c
*/

void sdl_loop(t_scene *s, t_visu *v);

/*
** Draw in SDL_Renderer for rendering
** in sdl_draw.c
*/

void sdl_draw(t_scene *s, t_visu *v);

/*
** Capture keyboard events to interact
** in sdl_event.c
*/

void sdl_event(t_events *e);

#endif
