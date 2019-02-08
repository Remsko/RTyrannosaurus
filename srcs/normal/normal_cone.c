/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:01:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 22:02:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"
#include "ray.h"
#include "object.h"

t_vector normal_cone(void *object, t_ray *ray, t_vector *hit)
{
    t_cone *cone;
    t_vector normal;

    (void)ray;
    cone = (t_cone *)object;
    normal = vector_sub_ret(hit, &cone->center);
    vector_rotate(&normal, &cone->rot);
    normal.y *= -tan(pow(cone->radius, 2));
    vector_unrotate(&normal, &cone->rot);
    vector_normalize(&normal);
    return (normal);
}