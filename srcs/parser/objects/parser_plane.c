/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:05:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 10:58:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "object.h"
#include "parser.h"

void    *parser_plane(t_json_object *o)
{
    t_plane *plane;

    if ((plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
        return (NULL);
    plane->center = parser_vector(getter_by_key(o, "center"));
    plane->normal = parser_vector(getter_by_key(o, "normal"));
    vector_normalize(&plane->normal);
    plane->rot = parser_vector(getter_by_key(o, "rot"));
    nerf_rotation(&plane->rot);
    return ((void *)plane);
}