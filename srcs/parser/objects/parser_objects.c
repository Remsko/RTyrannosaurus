/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:22 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:09:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "object.h"
#include "parser.h"

#include "json_types.h"

/*
** fonctionnel mais a refaire avec elegance !!!!!!!!!!!!!!!!!!!!
*/

#include    <stdio.h>

/* exit de crado dans les sous parser */

t_object *parser_objects(t_json_value *value)
{
    t_json_array *a;
    t_object *objects;
    uint32_t index;

    if (value_exist(value) == false || value->type != array)
        return (NULL);
    a = (t_json_array *)value->ptr;
    if ((objects = (t_object *)malloc(sizeof(t_object) * a->len)) == NULL)
        return (NULL);
    index = 0;
    while (index < a->len)
    {
        if (value_exist(a->value[index]) == false)
            exit(-1);
        objects[index].type = parser_object_type(a->value[index]);
        //printf("type = %d\n", objects[index].type);
        objects[index].spec = parser_object_spec(a->value[index], objects[index].type);
        ++index;
    }
    return (objects);
}