/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:39:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 22:52:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "solver.h"

/*
** TODO
** handle all cases (computer v1 like)
*/

int solver_quadratic(t_quadra quadra, double *t)
{
    double delta;
    double root1;
    double root2;

    delta = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
    if (delta < 0.0)
        return (0);
    delta = sqrt(delta);
    root1 = (-quadra.b + delta) * 0.5 / quadra.a;
    root2 = (-quadra.b - delta) * 0.5 / quadra.a;
    if (root1 < EPSILON && root2 < EPSILON)
        return (0);
    else if (root1 > EPSILON && root2 < EPSILON)
    {
        *t = root1;
        return (1);
    }
    else if (root1 < EPSILON && root2 > EPSILON)
    {
        *t = root2;
        return (1);
    }
    *t = root1 < root2 ? root1 : root2;
    return (2);
}