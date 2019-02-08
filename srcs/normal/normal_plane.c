/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:10:57 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 15:53:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "object.h"

t_vector normal_plane(void *object, t_ray *ray, t_vector *hit)
{
    t_plane *plane;
    t_vector normal;

    (void)hit;
    (void)ray;
    plane = (t_plane *)object;
    normal = plane->normal;
    //if (vector_dot_product(&ray->direction, &normal) > 0.0)
		//vector_multiply_const(&normal, -1.0);
    vector_normalize(&normal);
    return (normal);
}