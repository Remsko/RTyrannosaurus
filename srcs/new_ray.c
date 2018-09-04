/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:31:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 09:51:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray    new_ray(t_camera *cam, double x, double y)
{
    t_ray ray;

    ray.ori = cam->pos;
    ray.dir.x = x;
    ray.dir.y = y;
    ray.dir.z = cam->dist;
    return (ray);
}