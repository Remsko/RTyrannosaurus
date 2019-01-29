/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:13:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 12:47:56 by rpinoit          ###   ########.fr       */
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
    cone->rot = parser_vector(getter_by_key(o, "rot"));
    nerf_rotation(&cone->rot);
    cone->radius = parser_double(getter_by_key(o, "radius"));
    cone->radius = degree_to_radian(cone->radius);
    //sphere->mater = parser_mater(getter_by_key(o, "mater"));
    return ((void *)cone);
}