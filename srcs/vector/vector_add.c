/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:45:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 01:22:11 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Compute addition on a vector with a constant or an other vector
** return a new vector with pure function if necessary
*/

void    vector_add(t_vector *a, t_vector const b)
{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

void    vector_add_const(t_vector *vector, const double amount)
{
    vector->x += amount;
    vector->y += amount;
    vector->z += amount;
}

t_vector    vector_add_ret(t_vector const a, t_vector const b)
{
    t_vector ret;

    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    return (ret);
}

t_vector    vector_add_const_ret(t_vector const vector, const double amount)
{
    t_vector ret;

    ret.x = vector.x + amount;
    ret.y = vector.y + amount;
    ret.z = vector.z + amount;
    return (ret);
}
