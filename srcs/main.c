/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 18:03:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object new_object()
{
	t_object object;

	object.mater.ambient = (t_color){0, 0, 0};
	object.mater.diffuse = (t_color){0, 0, 0};
	object.mater.specular = (t_color){0, 0, 0};
	object.pos = (t_vector){0, 0, 0};
	object.rot = (t_vector){0, 0, 0};
	//object.type.sphere = 1;
	object.radius = 0;
	object.inter = &inter_sphere;
	return (object);
}

int	main(int ac, char **av)
{
	t_env	e;
	t_visu	v;

	(void)av;
	ft_bzero(&e, sizeof(t_env));
	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	t_object object = new_object();
	e.object = &object;
	e.object_nb = 1;
	t_camera camera;
	camera.pos = (t_vector){0, 0, -1000};
	camera.rot = (t_vector){0, 0, 0};
	camera.dist = 1000.0;
	e.camera = &camera;
	e.samples = 1;
	if (ac == 2)
	{
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
	}
	else
		ft_putstr("usage: ./rt <scene's file>\n");
	return (0);
}
