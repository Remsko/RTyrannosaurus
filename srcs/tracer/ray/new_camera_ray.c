/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:52:46 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 21:24:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tracer.h"
#include "ray.h"
#include "libft.h"

t_ray *new_camera_ray(const t_camera *camera, const t_position *position)
{
    t_ray *ray;

    if ((ray = (t_ray *)malloc(sizeof(t_ray))) != NULL)
    {
        ray->origin = camera->position;
        ray->direction.x = position->x;
        ray->direction.y = position->y;
        ray->direction.z = camera->distance;
        vector_rotate(&ray->direction, &camera->rotation);
        vector_normalize(&ray->direction);
    }
    return (ray);
}