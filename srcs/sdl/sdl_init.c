/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:26:59 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 18:25:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

/*
** SDL initialisation
*/

static void		sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(-1);
	}
}

static void		window(t_visu *v)
{
	if ((v->window = SDL_CreateWindow(
					"RT",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					v->screen.width,
					v->screen.height,
					0)) == NULL)
	{
        SDL_Log("Unable to create window: %s", SDL_GetError());
		exit(-2);
	}
}

static void		image(t_visu *v)
{
	if ((v->renderer = SDL_CreateRenderer(v->window,
					-1,
					SDL_RENDERER_SOFTWARE)) == NULL)
	{
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
		exit(-3);
	}
}

static void		texture(t_visu *v)
{
	if ((v->texture = SDL_CreateTexture(v->renderer,
					SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET,
					v->screen.width,
					v->screen.height)) == NULL)
	{
		SDL_Log("Unable to create texture: %s", SDL_GetError());
		exit(-4);
	}
}

void			sdl_init(t_visu *v)
{
	sdl();
	window(v);
	image(v);
	texture(v);
}
