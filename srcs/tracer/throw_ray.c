/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:48:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 22:44:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "color.h"
#include "ray.h"
#include "intersection.h"

#include "libft.h"

t_color phong_shading(t_scene *scene, t_object *victim, t_ray *ray, t_vector *hit);

t_color throw_ray(t_scene *scene, t_ray *ray)
{
    t_object *victim;
    t_vector hit_;
    t_color object_color;
    double t;

    if ((victim = hit(&t, ray, scene->objects, scene->n_object)) != NULL)
    {
        hit_ = vector_multiply_const_ret(&ray->direction, t);
        object_color = phong_shading(scene, victim, ray, &hit_);
        color_to_range_0_255(&object_color);
    }
    else
        ft_bzero((void *)&object_color, sizeof(t_color));
    return (object_color);
}