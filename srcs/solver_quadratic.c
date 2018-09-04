/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:50:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 12:00:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double  solver_quadratic(double a, double b, double c)
{
    double delta;
    double root1;
    double root2;

    delta = b * b - 4 * a * c;
    if (delta < 0.0)
        return (0.0);
    root1 = (b + sqrt(delta)) / (2.0 * a);
	root2 = (b - sqrt(delta)) / (2.0 * a);
    if (root1 < 0.0 && root2 < 0.0)
        return (0.0);
    if (root1 < root2)
        return (root1);
    return (root2);
}