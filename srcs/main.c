/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/04 18:53:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visu.h"
#include "scene.h"
#include "parser.h"

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
		if (scene->config != NULL)
			free(scene->config);
		if (scene->objects != NULL)
		{
			for (int i = 0; i < scene->n_object; i++)
			{
				free(scene->objects[i].spec);
				free(scene->objects[i].mater);
			}
			free(scene->objects);
		}
		if (scene->lights != NULL)
		{
			for (int i = 0; i < scene->n_light; i++)
				free(scene->lights[i].spec);
			free(scene->lights);
		}
		free(scene);
	}
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	t_visu	v;

	if (ac == 2)
	{
		if ((scene = parser_file(av[1])) == NULL)
			return (1);
		v.screen.width = (int)scene->config->viewplane.width;
		v.screen.height = (int)scene->config->viewplane.height;
		scene->camera->distance = scene->config->viewplane.width / 2.0 / tan(scene->camera->fov / 2.0 * M_PI / 180.0);
		sdl_init(&v);
		sdl_loop(scene, &v);
		sdl_destroy(&v);
		scene_in_the_poubelle(scene);
	}
	else
		usage(av[0]);
	return (0);
}