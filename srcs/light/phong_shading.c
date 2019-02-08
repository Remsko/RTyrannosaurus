/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:35:32 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 17:29:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "color.h"
#include "light.h"
#include "object.h"
#include "scene.h"
#include "normal.h"
#include "tracer.h"

#include "intersection.h"

bool shadow(t_scene *scene, t_ray *light_ray, double distance);

bool shadow_(t_scene *scene, t_ray *light_ray, double distance)
{
    t_object *victim;
    double t;

    t = DBL_MAX;
    //printf("scene->n_object = %d\n", scene->n_object);
    if (/*printf("shadow\n") && */(victim = hit(&t, light_ray, scene->objects, scene->n_object)) != NULL)
    {
        //printf("hitted\n");
        if (t < distance)
            return (true);
    }
    return (false);
}

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
#include <stdio.h>
t_color phong_shading(t_scene *scene, t_object *victim, t_ray *ray, t_vector *hit)
{
    //t_ray *light_ray;
    t_vector normal;
    t_color shading;
    double distance;
    double cos_teta;
    int index;

    shading = ambient(victim, scene->config->ambient);
    index = 0;
    while (index < scene->n_light)
    {
        t_light *light = &scene->lights[index];
        t_ray tmpray;
        tmpray.origin = *hit;
        tmpray.direction = vector_sub_ret(&((t_point *)light->spec)->source, hit);
        //light_ray = new_light_ray(light, hit);
        distance = vector_magnitude(&tmpray.direction);
        //printf("%f\n", distance);
        vector_normalize(&tmpray.direction);
        if (shadow_(scene, &tmpray, distance) == false)
        {
            normal = new_normal(victim, ray, hit);
            cos_teta = vector_dot_product(&tmpray.direction, &normal);
            if (cos_teta > 0.0)
                color_add(&shading, diffuse(victim, &scene->lights[index], cos_teta)); 
        }
        //free(light_ray);
        ++index;
    }
    return (shading);
}

/*
Ray lightRay = new Ray(new Point3D(intersection.position),
				new Vector3D(this.position.sub(intersection.position)));
                */