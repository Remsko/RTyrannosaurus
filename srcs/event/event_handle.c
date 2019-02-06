/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:36:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 12:45:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "scene.h"
#include "event.h"

bool event_handle(t_scene *scene, const unsigned char *keys)
{
	if (event_camera(scene->camera, keys))
		return (true);
	return (false);
}