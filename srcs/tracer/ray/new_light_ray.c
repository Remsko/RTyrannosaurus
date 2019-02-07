/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:22:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 21:39:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "ray.h"
#include "light.h"

static t_ray *point_light_ray(void *light, t_vector *hit)
{
    t_point *point;
    t_ray *ray;

    point = (t_point *)light;
    if ((ray = (t_ray *)malloc(sizeof(t_ray))) != NULL)
    {
        ray->origin = point->source;
        ray->direction = vector_sub_ret(&point->source, hit);
    }
    return (ray);
}

static t_ray *directional_light_ray(void *light, t_vector *hit)
{
    t_directional *directional;
    t_ray *ray;

    (void)hit;
    directional = (t_directional *)light;
    if ((ray = (t_ray *)malloc(sizeof(t_ray))) != NULL)
    {
        ray->origin = directional->source;
        ray->direction = vector_multiply_const_ret(&directional->direction, -1);
    }
    return (ray);
}

t_ray *new_light_ray(t_light *light, t_vector *hit)
{
    static t_ray *(*spec[LIGHT_MAX])(void *light, t_vector *hit) =
    {
        [POINT] = &point_light_ray,
        [DIRECTIONAL] = &directional_light_ray,
        //[PARALLEL] = &ray_parallel,
    };

    return (spec[light->type](light->spec, hit));
}