/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:26:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 13:43:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "camera.h"
# include "light.h"
# include "object.h"

# define WIN_W 1000
# define WIN_H 1000

/*
** Environment structure: Raytracer configurations
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
    //size_t o_length;
    t_light *lights;
    //size_t l_length;
} t_scene;

#endif
