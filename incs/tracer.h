/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 23:29:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:09:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

#include "scene.h"
#include "visu.h"

void    raytracer(t_scene *scene, t_visu *visu);

t_color throw_ray(t_scene *scene, t_ray *ray);

#endif