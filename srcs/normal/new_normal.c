/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:55:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 22:03:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "object.h"
#include "normal.h"

t_vector	new_normal(t_object *object, t_ray *ray, t_vector *hit)
{
	static t_vector	(*normal[OBJECT_MAX])(void *object, t_ray *ray, t_vector *hit) =
    {
		[SPHERE] = &normal_sphere,
		[PLANE] = &normal_plane,
		[CYLINDER] = &normal_cylinder,
		[CONE] = &normal_cone
	};

	return (normal[object->type](object->spec, ray, hit));
}