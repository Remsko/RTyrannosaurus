/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:05:16 by kehuang           #+#    #+#             */
/*   Updated: 2019/02/07 23:19:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

static void	rotate_axis(double *a, double *b, const double rad)
{
	double	tmp;
	double	cos_;
	double	sin_;

	cos_ = cos(rad);
	sin_ = sin(rad);
	tmp = *a;
	*a = *a * cos_ - *b * sin_;
	*b = tmp * sin_ + *b * cos_;
}

void	vector_rotate(t_vector *a, const t_vector *deg)
{
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	rotate_axis(&a->y, &a->z, rad.x);
	rotate_axis(&a->z, &a->x, rad.y);
	rotate_axis(&a->x, &a->y, rad.z);
}

void	vector_unrotate(t_vector *a, const t_vector *deg)
{
	t_vector	rad;

	rad = vector_multiply_const_ret(deg, M_PI / 180.0);
	rotate_axis(&a->y, &a->z, -rad.x);
	rotate_axis(&a->z, &a->x, -rad.y);
	rotate_axis(&a->x, &a->y, -rad.z);
}