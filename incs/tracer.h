/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 23:29:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 21:36:18 by rpinoit          ###   ########.fr       */
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

t_color throw_ray(t_scene *scene, t_ray *ray);

t_ray *new_camera_ray(const t_camera *camera, const t_position *position);

t_ray *new_light_ray(t_light *light, t_vector *hit);

t_ray *point_light_ray(void *light, t_vector *hit);

t_ray *directional_light_ray(void *light, t_vector *hit);

#endif