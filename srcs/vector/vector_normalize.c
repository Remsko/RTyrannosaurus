/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:47:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/05 19:56:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

/*
** Vector normalization to a length of one
*/

void		vector_normalize(t_vector *vector)
{
    vector_divide_const(vector, vector_magnitude(vector));
}

t_vector	vector_normalize_ret(const t_vector *vector)
{
    return (vector_divide_const_ret(vector, vector_magnitude(vector)));
}
