/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:11:46 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 22:50:02 by rpinoit          ###   ########.fr       */
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
    t_vector rotation;
    double fov;
} t_camera;

#endif