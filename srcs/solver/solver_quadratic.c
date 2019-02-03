/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_quadratic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:39:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/03 22:25:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "solver.h"

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