/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:50:50 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 02:41:08 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

/*
**	The plane normal will be set on creation something like
**	.x = 0.0;
**	.y = 1.0;
**	.z = 0.0;
*/

t_vector	normal_plane(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos)
{
	t_plane		*plan;
	t_vector	normal;

	(void)hit_pos;
	plan = (t_plane *)obj;
	normal = vector_rotate3(plan->normal, plan->rot);
	if (vector_dot_product(ray_dir, normal) > 0.0)
		normal = vector_multiply_const_ret(normal, -1.);
	return (normal);
}

int			intersection_plane(t_ray const ray, void const *obj, double *t)
{
	t_plane	*plan;
	double	div;

	plan = (t_plane *)obj;
	div = vector_dot_product(vector_rotate3(plan->normal, plan->rot),
			ray.direction);
	if (div == 0.)
		return (0);
	*t = vector_dot_product(vector_rotate3(plan->normal, plan->rot),
			vector_sub_ret(plan->center, ray.origin));
	if (*t <= 0.)
		return (0);
	return (1);
}
