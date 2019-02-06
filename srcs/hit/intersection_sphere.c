/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:15:42 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:17:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ray.h"
#include "object.h" 
#include "solver.h"

int intersection_sphere(const t_ray *ray, const void *object, double *t)
{
    t_sphere *sphere;
    t_vector rela;
    t_quadra quadra;

    sphere = (t_sphere *)object;
    rela = vector_sub_ret(&ray->origin, &sphere->center);
    quadra.a = 1.0;
    quadra.b = 2.0 * vector_dot_product(&ray->direction, &rela);
    quadra.c = vector_dot_product(&rela, &rela) - pow(sphere->radius, 2.0);
    return (solver_quadratic(quadra, t));
}