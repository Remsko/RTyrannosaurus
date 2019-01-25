/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:26:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/25 16:57:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include "camera.h"

#define WIN_W 1000
#define WIN_H 1000

/*
** Environment structure: Raytracer configurations
*/

typedef struct s_scene
{
    t_camera *camera;
} t_scene;

typedef struct s_env
{
    t_scene *scene;
} t_env;

#endif
