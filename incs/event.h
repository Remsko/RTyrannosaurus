/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:40:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 12:45:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>
#include "camera.h"
#include "scene.h"

#define CONST_ROT 10.0
#define CONST_TRANS 30.0

bool    event_camera(t_camera *camera, const unsigned char *keys);
bool    event_handle(t_scene *scene, const unsigned char *keys);

#endif