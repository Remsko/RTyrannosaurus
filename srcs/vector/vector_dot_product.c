/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:42:37 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 13:17:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Dot product calculation between two vectors
*/

double    vector_dot_product(t_vector *a, t_vector *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}