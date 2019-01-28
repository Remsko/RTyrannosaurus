/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:33:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 13:29:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "SDL.h"
#include "rt.h"
#include "camera.h"
#include "parser.h"

#include "json_getter.h"
#include <stdio.h>

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
    camera->rotation = parser_vector(getter_by_key(o, "rotation"));
    nerf_rotation(&camera->rotation);
    camera->fov = parser_double(getter_by_key(o, "fov"));
    nerf_double(&camera->fov, 1.0, 90.0);
    camera->distance_from_viewplane = 1000.0 / 2.0 / tan(camera->fov * M_PI / 180.0);
    /*
    printf("%f %f %f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("%f %f %f\n", camera->direction.x, camera->direction.y, camera->direction.z);
    printf("%f\n", camera->fov);
    */
    return (camera);
}