/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:56:01 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/27 13:44:51 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		solver_quadratic(const double a, const double b, const double c,
		double *t)
{
	double	delta;
	double	dis[2];

	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return (0);
	delta = sqrt(delta);
	dis[0] = (-b + delta) / (a * 0.5);
	dis[1] = (-b - delta) / (a * 0.5);
	if (dis[0] < 0.01 && dis[1] < 0.01)
		return (0);
	*t = (dis[0] < dis[1]) ? dis[0] : dis[1];
	return (1);
}
