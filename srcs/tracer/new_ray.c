/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:52:46 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 13:21:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ray.h"
#include "libft.h"

t_ray *new_ray(const t_camera *camera, const double vp_x, const double vp_y)
{
    t_ray *ray;

    if ((ray = (t_ray *)malloc(sizeof(t_ray))) != NULL)
    {
        ray->origin = camera->position;
        ray->direction.x = vp_x;
        ray->direction.y = vp_y;
        ray->direction.z = camera->distance;
        vector_rotate(&ray->direction, &camera->rotation);
        vector_normalize(&ray->direction);
    }
    return (ray);
}