/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:27:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 16:41:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "json_types.h"

#include "parser.h"
#include "object.h"

void    *parser_object_spec(t_json_value *value, t_object_type type)
{
    static void *(*spec[OBJECT_MAX])(t_json_object *) =
    {
        [SPHERE] = &parser_sphere,
        [PLANE] = &parser_plane,
        [CYLINDER] = &parser_cylinder,
        [CONE] = &parser_cone,
    };
    t_json_object *o;

    if (value->type != object)
        return (NULL);
    o = (t_json_object *)value->ptr;
    return (spec[type](o));
}