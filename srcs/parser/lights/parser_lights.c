/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 12:59:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "light.h"
#include "parser.h"

#include "json_types.h"

static void parse_each(t_light *lights, t_json_array *a)
{
    t_json_object *o;
    uint32_t index;

    index = 0;
    while (index < a->len)
    {
        if (value_exist(a->value[index]) == false || a->value[index]->type != object)
            exit (-1);
        o = (t_json_object *)a->value[index]->ptr;
        lights[index].type = parser_light_type(o);
        lights[index].spec = parser_light_spec(o, lights[index].type);
        ++index;
    }
}

t_light *parser_lights(t_json_value *value, int *n_light)
{
    t_json_array *a;
    t_light *lights;

    if (value_exist(value) == false || value->type != array)
        return (NULL);
    a = (t_json_array *)value->ptr;
    *n_light = (int)a->len;
    if ((lights = (t_light *)malloc(sizeof(t_light) * a->len)) == NULL)
        return (NULL);
    parse_each(lights, a);
    return (lights);
}