/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:03:28 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 16:07:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "utils.h"

void camera_rotate_pos(t_camera *camera)
{
    vector_rotate3(camera->rotation, ROT);
}

void camera_rotate_neg(t_camera *camera)
{
    vector_rotate3(camera->rotation, ROT);
}