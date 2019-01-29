/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:31:54 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 22:53:16 by rpinoit          ###   ########.fr       */
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

int solver_quadratic(t_quadra quadra, double *t);

#endif