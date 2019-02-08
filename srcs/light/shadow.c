/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:35:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 15:52:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <float.h>
#include "scene.h"
#include "ray.h"
#include "object.h"
#include "intersection.h"


#include <stdio.h>
static bool hard_shadow(t_scene *scene, t_ray *light_ray, double distance)
{
    t_object *victim;
    double t;

    t = DBL_MAX;
    //printf("scene->n_object = %d\n", scene->n_object);
    if (printf("shadow\n") && (victim = hit(&t, light_ray, scene->objects, scene->n_object)) != NULL)
    {
        printf("hitted\n");
        if (t < distance)
            return (true);
    }
    return (false);
}

bool shadow(t_scene *scene, t_ray *light_ray, double distance)
{
    bool shadow_ = hard_shadow(scene, light_ray, distance);

    printf(shadow_ ? "true\n" : "false\n");
    return (shadow_);
}