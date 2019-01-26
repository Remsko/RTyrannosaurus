/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:11:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 15:52:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rt.h"
#include "parser.h"
#include "camera.h"

#include "json_types.h"
#include "json_getter.h"

t_scene *parser_scene(t_json_object *json)
{
    t_scene *scene;

    if ((scene = (t_scene *)malloc(sizeof(t_scene))) == NULL)
        return (NULL);
    scene->camera = parser_camera(getter_by_key(json, "camera"));
    return (scene);
}