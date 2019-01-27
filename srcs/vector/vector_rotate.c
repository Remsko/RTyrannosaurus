/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:05:16 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 21:39:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vector	vector_rotate_x(t_vector const a, const double rad)
{
	t_vector	n;
	double		cos_;
	double		sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	n.x = a.x;
	n.y = a.y * cos_ - a.z * sin_;
	n.z = a.y * sin_ + a.z * cos_;
	return (n);
}

t_vector	vector_rotate_y(t_vector const a, const double rad)
{
	t_vector	n;
	double		cos_;
	double		sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	n.x = a.z * sin_ + a.x * cos_;
	n.y = a.y;
	n.z = a.z * cos_ - a.x * sin_;
	return (n);
}

t_vector	vector_rotate_z(t_vector const a, const double rad)
{
	t_vector	n;
	double		cos_;
	double		sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	n.x = a.x * cos_ - a.y * sin_;
	n.y = a.x * sin_ + a.y * cos_;
	n.z = a.z;
	return (n);
}

t_vector	vector_rotate3(t_vector const a, t_vector const deg)
{
	t_vector	r;
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	r = vector_rotate_x(a, rad.x);
	r = vector_rotate_y(r, rad.y);
	r = vector_rotate_z(r, rad.z);
	return (r);
}

t_vector	vector_unrotate3(t_vector const a, t_vector const deg)
{
	t_vector	r;
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	r = vector_rotate_x(a, -rad.x);
	r = vector_rotate_y(r, -rad.y);
	r = vector_rotate_z(r, -rad.z);
	return (r);
}
