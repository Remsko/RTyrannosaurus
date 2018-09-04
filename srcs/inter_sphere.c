/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:55:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 10:55:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double inter_sphere(t_object *object, t_ray *ray)
{
    t_vector relative;
    double root;
    double a;
    double b;
    double c;
    
    relative = vector_sub(ray->ori, object->pos);
    a = 1.0;
    b = 2.0 * vector_dot(relative, ray->dir);
    c = vector_dot(relative, relative) - object->radius;

    root = solver_quadratic(a, b, c);
    return (root);
}