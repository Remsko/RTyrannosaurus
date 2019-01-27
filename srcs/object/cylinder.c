/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:50:52 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 13:24:10 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

t_vector	normal_cylinder(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos)
{
	t_cylinder	*cyl;
	t_vector	normal;
	t_vector	tmp;

	(void)ray_dir;
	cyl = (t_cylinder *)obj;
	normal = vector_rotate3(vector_sub_ret(hit_pos, cyl->center), cyl->rot);
	tmp.x = 360. - cyl->rot.x;
	tmp.y = 0.0;
	tmp.z = 360. - cyl->rot.z;
	normal = vector_norm(vector_rotate3(normal, tmp));
	return (normal);
}

int		intersection_cylinder(t_ray const ray, void const *obj, double *t)
{
	t_cylinder	*cyl;
	t_vector	tmp;
	t_vector	oc;
	t_vector	dir;

	cyl = (t_cylinder *)obj;
	oc = vector_rotate3(vector_sub_ret(ray.origin, cyl->center), cyl->rot);
	dir = ray.direction;
	tmp.x = dir.x * dir.x + dir.z * dir.z;
	tmp.y = 2.0 * (dir.x * oc.x + dir.z * oc.z);
	tmp.z = oc.x * oc.x + oc.z * oc.z - cyl->radius * cyl->radius;
	return (solver_quadratic(tmp.x, tmp.y, tmp.z, t));
}
