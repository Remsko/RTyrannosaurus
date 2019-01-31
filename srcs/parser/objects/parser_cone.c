/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:13:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:03:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "utils.h"
#include "object.h"
#include "parser.h"

void    *parser_cone(t_json_object *o)
{
    t_cone *cone;

    if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
        return (NULL);
    cone->center = parser_vector(getter_by_key(o, "center"));
    cone->radius = parser_double(getter_by_key(o, "radius"));
    cone->radius = degree_to_radian(cone->radius);
    cone->rot = parser_vector(getter_by_key(o, "rot"));
    nerf_rotation(&cone->rot);
    return ((void *)cone);
}