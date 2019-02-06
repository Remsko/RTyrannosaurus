/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:37:55 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 12:41:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "camera.h"
#include "event.h"

static bool camera_rotate(t_vector *rot, const unsigned char *keys)
{
	if (keys[SDL_SCANCODE_UP])
	{
		rot->x -= CONST_ROT;
		return (true);
	}
	else if (keys[SDL_SCANCODE_DOWN])
	{
		rot->x += CONST_ROT;
		return (true);
	}
	else if (keys[SDL_SCANCODE_LEFT])
	{
		rot->y -= CONST_ROT;
		return (true);
	}
	else if (keys[SDL_SCANCODE_RIGHT])
	{
		rot->y += CONST_ROT;
		return (true);
	}
	return (false);
}

static bool camera_translate(t_vector *pos, const unsigned char *keys)
{
	if (keys[SDL_SCANCODE_W])
	{
		pos->y += CONST_TRANS;
		return (true);
	}
	else if (keys[SDL_SCANCODE_S])
	{
		pos->y -= CONST_TRANS;
		return (true);
	}
	else if (keys[SDL_SCANCODE_A])
	{
		pos->x -= CONST_TRANS;
		return (true);
	}
	else if (keys[SDL_SCANCODE_D])
	{
		pos->x += CONST_TRANS;
		return (true);
	}
	return (false);
}

bool	event_camera(t_camera *camera, const unsigned char *keys)
{
	if (camera_rotate(&camera->rotation, keys))
		return (true);
	if (camera_translate(&camera->position, keys))
		return (true);
	return (false);
}
