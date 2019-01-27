/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nerf_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:24:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 17:31:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parser.h"

void    nerf_rotation(t_vector *rot)
{
    nerf_double(&rot->x, -360.0, 360.0);
    nerf_double(&rot->y, -360.0, 360.0);
    nerf_double(&rot->z, -360.0, 360.0);
}