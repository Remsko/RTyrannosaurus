/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:35:32 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 20:17:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "math.h"
#include "color.h"
#include "light.h"
#include "object.h"
#include "scene.h"
#include "normal.h"
#include "tracer.h"

#include "intersection.h"

bool shadow(t_scene *scene, t_ray *light_ray, double distance);

static t_color ambient(t_object *object, double ambient)
{
    return (color_multiply_const_ret(&object->mater->ambient, ambient));
}

static t_color diffuse(t_object *object, t_light *light, double cos_teta)
{
    t_color diffuse;

    diffuse = object->mater->diffuse;
    color_multiply(&diffuse, light->color);
    color_multiply_const(&diffuse, light->intensity);
    color_multiply_const(&diffuse, cos_teta);
	return (diffuse);
}

static t_color specular(t_object *object, t_light *light, double cos_omega)
{
    t_color specular;

    specular = object->mater->specular;
    color_multiply_const(&specular, light->intensity);
    color_multiply_const(&specular, cos_omega);
    return (specular);
}

t_color phong_shading(t_scene *scene, t_object *victim, t_ray *ray, t_vector *hit)
{
    t_ray *light_ray;
    t_vector normal;
    t_vector vision;
    t_vector refracted;
    t_color shading;
    double distance;
    double cos_omega;
    double cos_teta;
    int index;

    shading = ambient(victim, scene->config->ambient);
    index = 0;
    while (index < scene->n_light)
    {
        light_ray = new_light_ray(&scene->lights[index], hit);
        distance = vector_magnitude(&light_ray->direction);
        vector_normalize(&light_ray->direction);
        if (shadow(scene, light_ray, distance) == false)
        {
            normal = new_normal(victim, ray, hit);
            cos_teta = vector_dot_product(&light_ray->direction, &normal);
            if (cos_teta > 0.0)
                color_add(&shading, diffuse(victim, &scene->lights[index], cos_teta));
            t_vector tmp = vector_multiply_const_ret(&normal, 2.0 * cos_teta);
            refracted = vector_sub_ret(&tmp, &light_ray->direction);
            vector_normalize(&refracted);
            vision = vector_sub_ret(&ray->origin, hit);
            vector_normalize(&vision);
            cos_omega = pow(fmax(vector_dot_product(&refracted, &vision), 0.0), 300.0);
            if (cos_omega > 0.0)
                color_add(&shading, specular(victim, &scene->lights[index], cos_omega));
        }
        free(light_ray);
        ++index;
    }
    shading.r = fmin(1.0, fmax(shading.r, 0.0));
    shading.g = fmin(1.0, fmax(shading.g, 0.0));
    shading.b = fmin(1.0, fmax(shading.b, 0.0));
    return (shading);
}