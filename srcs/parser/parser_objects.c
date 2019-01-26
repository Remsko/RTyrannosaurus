/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:22 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 00:34:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "object.h"

#include "json_types.h"

t_object *parser_objects(t_json_value *value)
{
    t_object *objects;

    if ((objects = (t_object *)malloc(sizeof(t_object))) == NULL)
        return (NULL);
    (void)value;
    return (objects);
}