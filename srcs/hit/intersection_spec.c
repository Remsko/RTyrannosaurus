/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:27:39 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 21:31:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "intersection.h"

int		intersection_spec(t_ray const ray, t_object const *obj, double *t)
{
	static int	(*intersection[OBJECT_MAX])(t_ray const ray, void const *object,
			double *t) = {
		[SPHERE] = &intersection_sphere,
		[PLANE] = &intersection_plane,
		[CYLINDER] = &intersection_cylinder,
		[CONE] = &intersection_cone
	};

	return (intersection[obj->type](ray, obj->spec, t));
}
