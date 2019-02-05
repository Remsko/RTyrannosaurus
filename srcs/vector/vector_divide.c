/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:49:58 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/05 19:48:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Compute division on a vector with a constant or an other vector
** return a new vector with pure function if necessary
*/

void    vector_divide(t_vector *a, const t_vector *b)
{
    a->x /= b->x;
    a->y /= b->y;
    a->z /= b->z;
}

void    vector_divide_const(t_vector *vector, const double amount)
{
    vector->x /= amount;
    vector->y /= amount;
    vector->z /= amount;
}

t_vector    vector_divide_ret(const t_vector *a, const t_vector *b)
{
    t_vector ret;

    ret.x = a->x / b->x;
    ret.y = a->y / b->y;
    ret.z = a->z / b->z;
    return (ret);
}

t_vector    vector_divide_const_ret(const t_vector *vector, const double amount)
{
    t_vector ret;

    ret.x = vector->x / amount;
    ret.y = vector->y / amount;
    ret.z = vector->z / amount;
    return (ret);
}