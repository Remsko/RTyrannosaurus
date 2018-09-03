/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:31:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 16:35:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray new_ray(t_camera *cam, double x, double y)
{
    t_ray ray;

    ft_bzero(&ray, sizeof(t_ray));
    (void)cam;
    (void)x;
    (void)y;
    return (ray);
}