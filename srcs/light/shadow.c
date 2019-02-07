/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:35:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 22:36:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "scene.h"
#include "ray.h"
#include "object.h"
#include "intersection.h"

static bool hard_shadow(t_scene *scene, t_ray *light_ray, double distance)
{
    double t;

    if (hit(&t, light_ray, scene->objects, scene->n_object) != NULL)
    {
        if (t < distance)
            return (true);
    }
    return (false);
}

bool shadow(t_scene *scene, t_ray *light_ray, double distance)
{
    return (hard_shadow(scene, light_ray, distance));
}