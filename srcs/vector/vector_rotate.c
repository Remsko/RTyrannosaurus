/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:05:16 by kehuang           #+#    #+#             */
/*   Updated: 2019/02/05 20:51:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

void	vector_rotate_x(t_vector *a, const double rad)
{
	double	tmp_y;
	double	cos_;
	double	sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	tmp_y = a->y;
	a->y = a->y * cos_ - a->z * sin_;
	a->z = tmp_y * sin_ + a->z * cos_;
}

void	vector_rotate_y(t_vector *a, const double rad)
{
	double	tmp_x;
	double	cos_;
	double	sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	tmp_x = a->x;
	a->x = a->z * sin_ + a->x * cos_;
	a->z = a->z * cos_ - tmp_x * sin_;
}

void	vector_rotate_z(t_vector *a, const double rad)
{
	double	tmp_x;
	double	cos_;
	double	sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	tmp_x = a->x;
	a->x = a->x * cos_ - a->y * sin_;
	a->y = tmp_x * sin_ + a->y * cos_;
}

void	vector_rotate3(t_vector *a, const t_vector *deg)
{
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	vector_rotate_x(a, rad.x);
	vector_rotate_y(a, rad.y);
	vector_rotate_z(a, rad.z);
}

void	vector_unrotate3(t_vector *a, const t_vector *deg)
{
	t_vector	r;
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	vector_rotate_x(a, -rad.x);
	vector_rotate_y(a, -rad.y);
	vector_rotate_z(a, -rad.z);
}
