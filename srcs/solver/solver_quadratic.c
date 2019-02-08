/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:39:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/08 14:10:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "solver.h"
/*
int solver_quadratic(const t_quadra quadra, double *t)
{
	double	delta;
	double	dis[2];

	delta = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	if (delta < 0.0)
		return (0);
	delta = sqrt(delta);
	dis[0] = (-quadra.b + delta) / (quadra.a * 0.5);
	dis[1] = (-quadra.b - delta) / (quadra.a * 0.5);
	if (dis[0] < 0.01 && dis[1] < 0.01)
		return (0);
	*t = (dis[0] < dis[1]) ? dis[0] : dis[1];
	return (1);
}*/
/*
int solver_quadratic(const t_quadra quadra, double *t)
{
    double delta;
	double x1;
	double x2;

	delta = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	if (delta < 0.000001)
		return (0);
	x1 = (-quadra.b + sqrt(delta)) / (2.0 * quadra.a);
	x2 = (-quadra.b - sqrt(delta)) / (2.0 * quadra.a);
	if (x1 < x2 && x1 > 0.000001)
    {
		*t = x1;
        return (1);
    }
	else if (x2 > 0.000001 && (x1 > x2 || x1 <= 0.000001))
    {
		*t = x2;
        return (1);
    }
	else if (x1 < 0.000001 && x2 < 0.000001)
    {
		*t = DBL_MAX;
        return (1);
    }
    return (0);
}*/

int solver_quadratic(const t_quadra quadra, double *t)
{
    double delta;
    double d;
    double root1;
    double root2;

    if (quadra.a == 0.0)
        return (solver_linear(quadra.b, quadra.c, t));
    delta = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
    if (delta > 0.0)
    {
        delta = sqrt(delta);
        d = 2 * quadra.a;
        root1 = (-quadra.b + delta) / d;
        root2 = (-quadra.b - delta) / d;
        if (root1 < 0.0 && root2 < 0.0)
            return (0);
        if (root1 < root2 && root1 > 0.0)
            *t = root1;
        else
            *t = root2;
        return (2);
    }
    else if (delta == 0.0)
    {
        *t = -0.5 * quadra.b / quadra.a;
        return (1);
    }
    return (0);
}