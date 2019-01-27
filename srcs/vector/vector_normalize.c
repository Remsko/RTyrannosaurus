/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:47:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 01:26:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

/*
** Vector normalization to a length of one
*/

void vector_normalize(t_vector *vector)
{
    vector_divide_const(vector, vector_magnitude(*vector));
}
