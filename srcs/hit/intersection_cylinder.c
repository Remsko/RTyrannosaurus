/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:33:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:16:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ray.h"
#include "object.h"
#include "solver.h"

int intersection_cylinder(const t_ray *ray, const void *object, double *t)
{
    t_cylinder *cylinder;
    t_quadra quadra;
    t_vector rela;
    t_vector dir;

    cylinder = (t_cylinder *)object;
    rela = vector_sub_ret(&ray->origin, &cylinder->center);
    vector_rotate(&rela, &cylinder->rot);
    dir = ray->direction;
    vector_rotate(&dir, &cylinder->rot);
    quadra.a = pow(dir.x, 2.0) + pow(dir.z, 2.0);
    quadra.b = 2.0 * (dir.x * rela.x + dir.z * rela.z);
    quadra.c = pow(rela.x, 2.0) + pow(rela.z, 2.0) - pow(cylinder->radius, 2.0);
    return (solver_quadratic(quadra, t));
}