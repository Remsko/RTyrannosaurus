/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:11:46 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:03:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

/*
** Camera structure is the eye/start or point of view of the scene
*/

typedef struct s_camera
{
    t_vector position;
    t_vector direction;
    double fov;
    double distance_from_viewplane;
} t_camera;

#endif