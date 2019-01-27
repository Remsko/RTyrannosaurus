/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:04:05 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 02:16:10 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

int		get_inter(t_ray const ray, t_object const *obj, double *t)
{
	static int	(*inter[object_max])(t_ray const ray, void const *obj,
			double *t) = {
		[sphere] = &intersection_sphere,
		[plane] = &intersection_plane,
		[cylinder] = &intersection_cylinder,
		[cone] = &intersection_cone
	};

	return (inter[obj->type](ray, obj->spec, t));
}
