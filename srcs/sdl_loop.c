/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/01 14:26:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    sdl_loop(t_env *e, t_visu *v)
{
	ft_bzero(&e->events, sizeof(t_events));
	while (e->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&e->events);
		if (e->events.options.draw == TRUE)
			sdl_draw(v);
	}
}
