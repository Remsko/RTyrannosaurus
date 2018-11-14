/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 10:15:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "visu.h"

void    sdl_loop(t_env *e, t_visu *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	v->events.options.draw = 1;
	while (v->events.options.exit == 0)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == 1)
		{
			sdl_draw(e, v);
			v->events.options.draw = 0;
		}
	}
}
