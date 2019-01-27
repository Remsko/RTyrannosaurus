/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:04:11 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 13:09:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

t_vector	get_normal(t_object const *obj, t_vector const ray_dir,
		t_vector const hit_pos)
{
	static t_vector	(*normal[OBJECT_MAX])(void const *obj,
			t_vector const ray_dir, t_vector const hit_pos) = {
		[SPHERE] = &normal_sphere,
		[PLANE] = &normal_plane,
		[CYLINDER] = &normal_cylinder,
		[CONE] = &normal_cone
	};

	return (normal[obj->type](obj->spec, ray_dir, hit_pos));
}
