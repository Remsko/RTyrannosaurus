/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:04:55 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:16:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ray.h"
#include "object.h"
#include "solver.h"

int intersection_cone(const t_ray *ray, const void *object, double *t)
{
    t_cone *cone;
    t_quadra quadra;
    t_vector rela;
    t_vector dir;
    double radius;

    cone = (t_cone *)object;
    radius = pow(cone->radius, 2.0);
    rela = vector_sub_ret(&ray->origin, &cone->center);
    vector_rotate(&rela, &cone->rot);
    dir = ray->direction;
    vector_rotate(&dir, &cone->rot);
    quadra.a = pow(dir.x, 2.0) - pow(dir.y, 2.0) * radius + pow(dir.z, 2.0);
    quadra.b = 2.0 * (dir.x * rela.x - dir.y * rela.y * radius + dir.z * rela.z);
    quadra.c = pow(rela.x, 2.0) - pow(rela.y, 2.0) * radius + pow(rela.z, 2.0);
    return (solver_quadratic(quadra, t));
}