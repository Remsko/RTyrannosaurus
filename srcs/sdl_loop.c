/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 12:52:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    sdl_loop(t_env *e, t_visu *v)
{
	ft_bzero(&e->events, sizeof(t_events));
	ft_putnbr(e->events.options.exit);
	while (e->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&e->events);
		if (e->events.options.draw == TRUE)
		{
			ft_putstr("New render !");
			sdl_draw(e, v);
		}
	}
}
