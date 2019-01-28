/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:31:10 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/28 13:14:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rt.h"
#include "parser.h"

#include "json_types.h"
#include "json_getter.h"

#include "libft.h"

#include    <stdio.h>

t_viewplane parser_viewplane(t_json_value *value)
{
    t_json_array *a;
    t_viewplane v;

    ft_bzero(&v, sizeof(t_viewplane));
    if (value_exist(value) && value->type == array)
    {
        a = (t_json_array *)value->ptr;
        if (a->len == 2)
        {
            v.width = parser_double(a->value[0]);
            v.height = parser_double(a->value[1]);
        }
    }
    return (v);
}

t_config *parser_config(t_json_value *value)
{
    t_config *config;
    t_json_object *o;

    if (value_exist(value) == false || value->type != object)
        return (NULL);
    if ((config = (t_config *)malloc(sizeof(t_config))) == NULL)
        return (NULL);
    o = (t_json_object *)value->ptr;
    config->viewplane = parser_viewplane(getter_by_key(o, "viewplane"));
    nerf_double(&config->viewplane.width, 1.0, 3000.0);
    nerf_double(&config->viewplane.height, 1.0, 3000.0);
    config->ambient = parser_double(getter_by_key(o, "ambient"));
    nerf_double(&config->ambient, 0.0, 1.0);
    config->anti_aliasing = parser_double(getter_by_key(o, "anti-aliasing"));
    //nerf_int(&config->anti_aliasing, 1, 4);
    /*
    printf("vp = %f %f\n", config->viewplane.width, config->viewplane.height);
    printf("ambient = %f\n", config->ambient);
    */
    return (config);
}