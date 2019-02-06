/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:39:57 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:16:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "solver.h"

int intersection_plane(const t_ray *ray, void const *object, double *t)
{
    t_plane *plane;
    t_vector rela;
    double denominator;

    plane = (t_plane *)object;
    denominator = vector_dot_product(&ray->direction, &plane->normal);
    if (denominator == 0.0)
        return (0);
    rela = vector_sub_ret(&plane->center, &ray->origin);
    *t = vector_dot_product(&rela, &plane->normal) / denominator;
    if (*t > EPSILON)
        return (1);
    return (0);
}