/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:22:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:31:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "json_types.h"

#include "parser.h"
#include "light.h"

void    *parser_light_spec(t_json_value *value, t_light_type type)
{
    static void *(*spec[LIGHT_MAX])(t_json_object *) =
    {
        [POINT] = &parser_point,
        [DIRECTIONAL] = &parser_directional,
        [PARALLEL] = &parser_parallel,
    };
    t_json_object *o;

    if (value->type != object)
        return (NULL);
    o = (t_json_object *)value->ptr;
    return (spec[type](o));
}