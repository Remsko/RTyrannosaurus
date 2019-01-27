/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:04:05 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 13:08:26 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

int		get_inter(t_ray const ray, t_object const *obj, double *t)
{
	static int	(*inter[OBJECT_MAX])(t_ray const ray, void const *obj,
			double *t) = {
		[SPHERE] = &intersection_sphere,
		[PLANE] = &intersection_plane,
		[CYLINDER] = &intersection_cylinder,
		[CONE] = &intersection_cone
	};

	return (inter[obj->type](ray, obj->spec, t));
}
