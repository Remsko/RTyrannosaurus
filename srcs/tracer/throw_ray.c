/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:48:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:19:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "color.h"
#include "ray.h"
#include "intersection.h"

#include "libft.h"

t_color throw_ray(t_scene *scene, t_ray *ray)
{
    t_object *victim;
    t_color object_color;

    if ((victim = hit(ray, scene->objects, scene->n_object)) != NULL)
    {
        object_color = victim->mater->ambient;
        color_to_range_0_255(&object_color);
    }
    else
        ft_bzero((void *)&object_color, sizeof(t_color));
    return (object_color);
}