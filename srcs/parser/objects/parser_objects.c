/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:22 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/30 21:24:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "object.h"
#include "parser.h"

#include "json_types.h"
#include "json_getter.h"

#include    <stdio.h>

/* exit de crado dans les sous parser */

static void parse_each(t_object *objects, t_json_array *a)
{
    t_json_object *o;
    uint32_t index;

    index = 0;
    while (index < a->len)
    {
        if (value_exist(a->value[index]) == false || a->value[index]->type != object)
            exit (-1);
        o = (t_json_object *)a->value[index]->ptr;
        objects[index].type = parser_object_type(o);
        objects[index].spec = parser_object_spec(o, objects[index].type);
        objects[index].mater = parser_material(getter_by_key(o, "material"));
        ++index;
    }
}

t_object *parser_objects(t_json_value *value, int *n_object)
{
    t_json_array *a;
    t_object *objects;

    if (value_exist(value) == false || value->type != array)
        return (NULL);
    a = (t_json_array *)value->ptr;
    *n_object = (int)a->len;
    if ((objects = (t_object *)malloc(sizeof(t_object) * a->len)) == NULL)
        return (NULL);
    parse_each(objects, a);
    return (objects);
}