/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:02:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/30 20:08:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "color.h"
#include "parser.h"

#include "json_getter.h"

t_material *parser_material(t_json_value *value)
{
    t_material *mater;
    t_json_object *o;

    if (value_exist(value) == false || value->type != object)
        return (NULL);
    if ((mater = (t_material *)malloc(sizeof(t_material))) == NULL)
        return (NULL);
    o = (t_json_object *)value->ptr;
    mater->ambient = parser_color(getter_by_key(o, "ambient"));
    nerf_color(&mater->ambient);
    mater->diffuse = parser_color(getter_by_key(o, "diffuse"));
    nerf_color(&mater->ambient);
    mater->specular = parser_color(getter_by_key(o, "specular"));
    nerf_color(&mater->ambient);
    return (mater);
}