/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:35:33 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 10:49:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool  inter_algo(t_object *object, t_ray *ray, int object_nb)
{
    double t;
    double tmp;
    int i;

    t = 0x7FFFFFFF;
    i = 0;
    while (i < object_nb)
    {
        tmp = object[i].inter(ray);
        if (tmp < t)
            t = tmp;
        ++i;
    }
    if (t == 0x7FFFFFFF)
        return (FALSE);
    return (TRUE);
}