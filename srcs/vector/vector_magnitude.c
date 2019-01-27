/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_magnitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:55:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 01:25:48 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

/*
** Vector length calculation
*/

double vector_magnitude(t_vector const vector)
{
    return (sqrt(vector_dot_product(vector, vector)));
}
