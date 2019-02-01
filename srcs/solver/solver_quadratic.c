/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:39:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/01 22:41:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "solver.h"

int solver_quadratic(t_quadra quadra, double *t)
{
    double delta;
    double root1;
    double root2;

    if (quadra.a == 0.0)
        return (solver_linear(quadra.b, quadra.c, t));
    delta = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
    if (delta > 0.0)
    {
        delta = sqrt(delta);
        root1 = (-quadra.b + delta) * 0.5 / quadra.a;
        root2 = (-quadra.b - delta) * 0.5 / quadra.a;
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