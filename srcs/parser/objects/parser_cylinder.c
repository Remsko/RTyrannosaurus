/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:15:48 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:03:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "object.h"
#include "parser.h"

void    *parser_cylinder(t_json_object *o)
{
    t_cylinder *cylinder;

    if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
        return (NULL);
    cylinder->center = parser_vector(getter_by_key(o, "center"));
    cylinder->radius = parser_double(getter_by_key(o, "radius"));
    cylinder->rot = parser_vector(getter_by_key(o, "rot"));
    nerf_rotation(&cylinder->rot);
    return ((void *)cylinder);
}