/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 18:49:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "scene.h"
#include "visu.h"

#include "libft.h"

/*
** Drawing loop
*/

bool	camera_event(t_camera *camera, const unsigned char *keys)
{
	if (keys[SDL_SCANCODE_UP])
	{
		camera->rotation.x -= 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_DOWN])
	{
		camera->rotation.x += 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_LEFT])
	{
		camera->rotation.y -= 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_RIGHT])
	{
		camera->rotation.y += 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_W])
	{
		camera->position.y += 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_S])
	{
		camera->position.y -= 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_A])
	{
		camera->position.x -= 10.0;
		return (true);
	}
	if (keys[SDL_SCANCODE_D])
	{
		camera->position.x += 10.0;
		return (true);
	}
	return (false);
}

bool handle_event(t_scene *scene, const unsigned char *keys)
{
	if (camera_event(scene->camera, keys))
		return (true);
	return (false);
}

void    sdl_loop(t_scene *s, t_visu *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	v->events.options.draw = 1;
	while (v->events.options.exit == 0)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == 1)
		{
			sdl_draw(s, v);
			v->events.options.draw = 0;
		}
		if (handle_event(s, v->events.keys))
			v->events.options.draw = 1;
	}
}
