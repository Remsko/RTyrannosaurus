/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:30:23 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 21:36:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vector.h"

/*
** Ray structure thrown from camera's position
*/

typedef struct s_ray
{
    t_vector origin;
    t_vector direction;
} t_ray;

#endif