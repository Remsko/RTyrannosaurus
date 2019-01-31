/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 21:21:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "scene.h"
#include "visu.h"

#include "libft.h"

/*
** Drawing loop
*/

bool camera_rotate(t_vector *rot, const unsigned char *keys)
{
	if (keys[SDL_SCANCODE_UP])
	{
		rot->x -= 10.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_DOWN])
	{
		rot->x += 10.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_LEFT])
	{
		rot->y -= 10.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_RIGHT])
	{
		rot->y += 10.0;
		return (true);
	}
	return (false);
}

bool camera_translate(t_vector *pos, const unsigned char *keys)
{
	if (keys[SDL_SCANCODE_W])
	{
		pos->y += 30.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_S])
	{
		pos->y -= 30.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_A])
	{
		pos->x -= 30.0;
		return (true);
	}
	else if (keys[SDL_SCANCODE_D])
	{
		pos->x += 30.0;
		return (true);
	}
	return (false);
}

bool	camera_event(t_camera *camera, const unsigned char *keys)
{
	if (camera_rotate(&camera->rotation, keys))
		return (true);
	if (camera_translate(&camera->position, keys))
		return (true);
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
