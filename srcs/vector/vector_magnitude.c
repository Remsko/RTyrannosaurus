/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_magnitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:55:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 13:17:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

/*
** Vector length calculation
*/

double vector_magnitude(t_vector *vector)
{
    return (
        sqrt(
            vector_dot_product(vector, vector)
        )
    );
}