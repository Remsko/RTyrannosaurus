/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:11:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 23:01:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scene.h"
#include "parser.h"

#include "json_types.h"
#include "json_getter.h"

/*
** TODO
** handle parsing error (null value returned)
*/

t_scene *parser_scene(t_json_object *json)
{
    t_scene *scene;

    if ((scene = (t_scene *)malloc(sizeof(t_scene))) == NULL)
        return (NULL);
    scene->config = parser_config(getter_by_key(json, "config"));
    scene->camera = parser_camera(getter_by_key(json, "camera"));
    scene->objects = parser_objects(getter_by_key(json, "objects"), &scene->n_object);
    scene->lights = parser_lights(getter_by_key(json, "lights"), &scene->n_light);
    return (scene);
}