/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:53:35 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 18:04:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "ray.h"

#include <stdio.h>
bool    hit(t_object *objects, int objects_length, t_ray ray)
{
    static int (*intersection[OBJECT_MAX])(t_ray const ray, void const *obj, double *t) =
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

    t = 0x7fffffff;
    index = 0;
    while (index < objects_length)
    {
        tested = &objects[index];
        if (intersection[tested->type](ray, tested->spec, &tmp))
        {
            if (tmp > 0.0 && tmp < t)
			    t = tmp;
        }
        ++index;
    }
    if (t != 0x7fffffff)
        return (true);
    return (false);
}