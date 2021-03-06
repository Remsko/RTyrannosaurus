/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:53:35 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 17:42:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <float.h>

#include "intersection.h"
#include "object.h"
#include "ray.h"

t_object *hit(double *t, t_ray *ray, t_object *objects, int n_object)
{
    t_object *victim;
    double tmp;
    int index;

    victim = NULL;
    *t = DBL_MAX;
    index = 0;
    while (index < n_object)
    {
        if (intersection_spec(ray, &objects[index], &tmp))
        {
            if (tmp > 0.0 && tmp < *t)
            {
			    *t = tmp;
                victim = &objects[index];
            }
        }
        ++index;
    }
    return (victim);
}