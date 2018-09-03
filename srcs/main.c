/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 12:39:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_env	e;
	t_visu	v;

	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	(void)av;
	if (ac == 2)
	{
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
	}
	return (0);
}
