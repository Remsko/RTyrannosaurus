/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:30:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 22:35:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "camera.h"
#include "object.h"
#include "light.h"

/*
** Scene data-structure that contain the scene describe in a json file
*/

typedef struct s_viewplane
{
    double width;
    double height;
} t_viewplane;

typedef struct s_config
{
    t_viewplane viewplane;
    double ambient;
    int anti_aliasing;
} t_config;

typedef struct s_scene
{
    t_config *config;
    t_camera *camera;
    t_object *objects;
    t_light *lights;
    int n_object;
    int n_light;
} t_scene;

#endif