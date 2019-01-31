/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:41:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:11:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "object.h"
#include "parser.h"

void    *parser_sphere(t_json_object *o)
{
    t_sphere *sphere;

    if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
        return (NULL);
    sphere->center = parser_vector(getter_by_key(o, "center"));
    sphere->radius = parser_double(getter_by_key(o, "radius"));
    sphere->rot = parser_vector(getter_by_key(o, "rot"));
    nerf_rotation(&sphere->rot);
    return ((void *)sphere);
}