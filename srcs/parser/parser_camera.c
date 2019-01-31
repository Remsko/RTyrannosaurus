/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:33:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:18:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "camera.h"
#include "parser.h"

#include "json_getter.h"

t_camera *parser_camera(t_json_value *value)
{
    t_camera *camera;
    t_json_object *o;

    if (value_exist(value) == false || value->type != object)
        return (NULL);
    if ((camera = (t_camera *)malloc(sizeof(t_camera))) == NULL)
        return (NULL);
    o = (t_json_object *)value->ptr;
    camera->position = parser_vector(getter_by_key(o, "position"));
    camera->position.z *= -1;
    camera->fov = parser_double(getter_by_key(o, "fov"));
    nerf_double(&camera->fov, 1.0, 90.0);
    camera->rotation = parser_vector(getter_by_key(o, "rotation"));
    nerf_rotation(&camera->rotation);
    return (camera);
}