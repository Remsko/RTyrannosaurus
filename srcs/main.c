/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 19:27:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "parser.h"
//#include "visu.h"

void usage(char *bin)
{
	ft_putstr("usage: ");
	ft_putstr(bin);
	ft_putstr("<scene file>\n");
}

void scene_in_the_poubelle(t_scene *scene)
{
	if (scene != NULL)
	{
		if (scene->camera != NULL)
			free(scene->camera);
		free(scene);
	}
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	//t_visu	v;

	//v.screen.width = WIN_W;
	//v.screen.height = WIN_H;
	if (ac == 2)
	{
		if ((scene = parser_file(av[1])) == NULL)
			return (1);
		//sdl_init(&v);
		//sdl_loop(scene, &v);
		//sdl_destroy(&v);
		scene_in_the_poubelle(scene);
	}
	else
		usage(av[0]);
	return (0);
}
