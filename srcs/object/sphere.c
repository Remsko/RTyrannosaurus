/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:50:49 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/28 21:30:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

t_vector	normal_sphere(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos)
{
	(void)ray_dir;
	return (vector_norm(vector_sub_ret(hit_pos, ((t_sphere *)obj)->center)));
}

int			intersection_sphere(t_ray const ray, void const *obj, double *t)
{
	t_sphere	*sph;
	t_vector	tmp;
	t_vector	oc;

	sph = (t_sphere *)obj;
	oc = vector_sub_ret(ray.origin, sph->center);
	tmp.x = vector_dot_product(ray.direction, ray.direction);
	tmp.y = 2.0 * vector_dot_product(ray.direction, oc);
	tmp.z = vector_dot_product(oc, oc) - sph->radius * sph->radius;
	return (solver_quadratic(tmp.x, tmp.y, tmp.z, t));
}
