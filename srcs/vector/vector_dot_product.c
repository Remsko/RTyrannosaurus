/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:42:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/05 19:51:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Dot product calculation between two vectors
*/

double    vector_dot_product(t_vector const *a, t_vector const *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}
