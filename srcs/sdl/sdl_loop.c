/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 18:23:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "visu.h"

#include "libft.h"

/*
** Drawing loop
*/

void    sdl_loop(t_scene *scene, t_visu *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	v->events.options.draw = 1;
	while (v->events.options.exit == 0)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == 1)
		{
			sdl_draw(scene, v);
			v->events.options.draw = 0;
		}
	}
}
