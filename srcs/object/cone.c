/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:50:53 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 13:24:21 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

t_vector	normal_cone(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos)
{
	t_cone		*c;
	t_vector	normal;
	t_vector	tmp;

	(void)ray_dir;
	c = (t_cone *)obj;
	normal = vector_rotate3(vector_sub_ret(hit_pos, c->center), c->rot);
	tmp.x = 360.0 - c->rot.x;
	tmp.y = 360.0 - c->rot.y;
	tmp.z = 360.0 - c->rot.z;
	normal = vector_norm(vector_rotate3(normal, tmp));
	return (normal);
}

int		intersection_cone(t_ray const ray, void const *obj, double *t)
{
	t_cone		*c;
	t_vector	tmp;
	t_vector	oc;
	t_vector	dir;
	double		pow_r;

	c = (t_cone *)obj;
	oc = vector_rotate3(vector_sub_ret(ray.origin, c->center), c->rot);
	pow_r = c->radius * c->radius;
	dir = ray.direction;
	tmp.x = dir.x * dir.x - pow_r * dir.y * dir.y + dir.z * dir.z;
	tmp.y = 2.0 * (dir.x * oc.x - pow_r * dir.y * oc.y + dir.z * oc.z);
	tmp.z = oc.x * oc.x - pow_r * oc.y * oc.y + oc.z * oc.z;
	return (solver_quadratic(tmp.x, tmp.y, tmp.z, t));
}