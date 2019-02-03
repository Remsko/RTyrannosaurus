/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:31:54 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/03 22:27:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

#define EPSILON 10E-9

typedef struct s_quadra
{
    double a;
    double b;
    double c;
} t_quadra;

int solver_linear(const double a, const double b, double *t);

int solver_quadratic(const t_quadra quadra, double *t);

#endif