/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:53:35 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 10:14:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "ray.h"

bool    hit(t_object *objects, t_ray *ray, int objects_length)
{
    static double (*intersection[OBJECT_MAX])(void *obj, t_ray *ray) =
    {
		[SPHERE] = &intersection_sphere,
		[PLANE] = &intersection_plane,
		[CYLINDER] = &intersection_cylinder,
		[CONE] = &intersection_cone
    };
    t_object *tested;
    double tmp;
    double t;
    int index;

    index = 0;
    while (index < objects_length)
    {
        tested = &objects[index];
        tmp = intersection[tested->type](tested->spec, ray);
        if (tmp != 0.0 && tmp < t)
			t = tmp;
        ++index;
    }
    return (false);
}