/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 23:04:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "light.h"
#include "parser.h"

#include "json_types.h"

t_light *parser_lights(t_json_value *value, int *n_light)
{
    t_json_array *a;
    t_light *lights;
    uint32_t index;

    if (value_exist(value) == false || value->type != array)
        return (NULL);
    a = (t_json_array *)value->ptr;
    *n_light = (int)a->len;
    if ((lights = (t_light *)malloc(sizeof(t_light) * a->len)) == NULL)
        return (NULL);
    index = 0;
    while (index < a->len)
    {
        if (value_exist(a->value[index]) == false)
            exit(-1);
        lights[index].type = parser_light_type(a->value[index]);
        //printf("type = %d\n", lights[index].type);
        lights[index].spec = parser_light_spec(a->value[index], lights[index].type);
        ++index;
    }
    return (lights);
}