/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 23:29:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 19:37:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

#include "scene.h"
#include "visu.h"

void    raytracer(t_scene *scene, t_visu *visu);

t_pixel   regular_sample(t_screen *screen, int row, int column, int x, int y, int samples);

t_pixel   jittered_sample(t_screen *screen, int row, int column, int x, int y, int samples);

t_ray   *new_ray(const t_camera *camera, t_pixel *pixel);

t_color throw_ray(t_scene *scene, t_ray *ray);


#endif