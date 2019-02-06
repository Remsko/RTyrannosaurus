/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 12:44:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "scene.h"
#include "visu.h"

#include "libft.h"
#include "event.h"

/*
** Drawing loop
*/

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
		if (event_handle(s, v->events.keys))
			v->events.options.draw = 1;
	}
}
