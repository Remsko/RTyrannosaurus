/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:33:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 16:38:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "rt.h"
#include "camera.h"
#include "parser.h"

#include "json_parser.h"
#include "json_getter.h"

#define PI 3.1416
#include <stdio.h>

double parser_double(t_json_value *value)
{
    if (value == NULL || value->ptr == NULL)
        return (0.0);
    if (value->type != number && value->type != integer)
        return (0.0);
    return (*(double *)value->ptr);
}

static double parser_fov(t_json_value *value)
{
    double fov;

    fov = parser_double(value);
    if (fov < 1.0 || fov > 90.0)
        fov = 90.0;
    return (fov);
}

double to_radians(double deg)
{
    return (PI * deg / 180.0);
}

t_camera *parser_camera(t_json_value *value)
{
    t_camera *camera;
    t_json_object *o;
    double fov;

    if (value == NULL || value->type != object)
        return (NULL);
    if ((camera = (t_camera *)malloc(sizeof(t_camera))) == NULL)
        return (NULL);
    o = (t_json_object *)value->ptr;
    camera->position = parser_vector(getter_by_key(o, "position"));
    camera->direction = parser_vector(getter_by_key(o, "direction"));
    fov = parser_fov(getter_by_key(o, "fov"));
    camera->distance_from_viewplane = WIN_H / 2.0 / tan(to_radians(fov));
    printf("vector 1 = %f %f %f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("vector 2 = %f %f %f\n", camera->direction.x, camera->direction.y, camera->direction.z);
    printf("dist = %f\n", camera->distance_from_viewplane);
    return (camera);
}