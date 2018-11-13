/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:45:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:32:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void    vector_add(t_vector *a, t_vector *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

void    vector_add_const(t_vector *vector, const double amount)
{
    vector->x += amount;
    vector->y += amount;
    vector->z += amount;
}

t_vector    vector_add_ret(t_vector *a, t_vector *b)
{
    t_vector ret;

    ret.x = a->x + b->x;
    ret.y = a->y + b->y;
    ret.z = a->z + b->z;
    return (ret);
}

t_vector    vector_add_const_ret(t_vector *vector, const double amount)
{
    t_vector ret;

    ret.x = vector->x + amount;
    ret.y = vector->y + amount;
    ret.z = vector->z + amount;
    return (ret);
}