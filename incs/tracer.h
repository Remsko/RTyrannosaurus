/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 23:29:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 21:39:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

#include "scene.h"
#include "visu.h"

typedef struct s_position
{
    double x;
    double y;
}   t_position;

void    raytracer(t_scene *scene, t_visu *visu);

t_position regular_sample(t_screen *screen, t_pixel *pixel, int row, int column, int samples);

t_position jittered_sample(t_screen *screen, t_pixel *pixel, int row, int column, int samples);

t_ray   *new_ray(const t_camera *camera, const t_position *position);

t_color throw_ray(t_scene *scene, t_ray *ray);


#endif