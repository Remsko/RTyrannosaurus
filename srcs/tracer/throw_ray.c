/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:48:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 13:00:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "color.h"
#include "ray.h"

#include "libft.h"

#include <stdbool.h>
bool    hit(t_object *objects, int objects_length, t_ray ray);

t_color throw_ray(t_scene *scene, t_ray ray)
{
    //t_intersection inter;
    t_color color;

    //inter = hit();
    if (hit(scene->objects, 1, ray))
        color = (t_color){255.0, 0.0, 0.0};
    else
        ft_bzero((void *)&color, sizeof(t_color));
    return (color);
}