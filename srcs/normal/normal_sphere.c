/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:07:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 23:21:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "object.h"

t_vector normal_sphere(void *object, t_ray *ray, t_vector *hit)
{
    t_sphere *sphere;
    t_vector normal;

    (void)ray;
    sphere = (t_sphere *)object;
    normal = vector_sub_ret(hit, &sphere->center);
    vector_normalize(&normal);
    return (normal);
}