/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:27:39 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:30:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "intersection.h"

int		intersection_spec(const t_ray *ray, const t_object *obj, double *t)
{
	static int (*i[OBJECT_MAX])(const t_ray *ray, const void *spec, double *t) =
	{
		[SPHERE] = &intersection_sphere,
		[PLANE] = &intersection_plane,
		[CYLINDER] = &intersection_cylinder,
		[CONE] = &intersection_cone
	};

	return (i[obj->type](ray, obj->spec, t));
}
