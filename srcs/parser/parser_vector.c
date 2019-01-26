/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:54:58 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:43:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parser.h"

#include "json_parser.h"

#include "libft.h"

static bool check_vector(t_json_array *a)
{
    t_json_value *v;
    int index;

    if (a->len != 3)
        return (false);
    index = 0;
    while (index < 3)
    {
        v = a->value[index];
        if (value_exist(v) == false)
            return (false);
        if (v->type != number && v->type != integer)
            return (false);
        ++index;
    }
    return (true);
}

static t_vector new_vector(t_json_array *a)
{
    t_vector v;

    v.x = value_to_double(a->value[0]->ptr, a->value[0]->type);
    v.y = value_to_double(a->value[1]->ptr, a->value[1]->type);;
    v.z = value_to_double(a->value[2]->ptr, a->value[2]->type);;
    return (v);
}

t_vector parser_vector(t_json_value *value)
{
    t_vector v;

    ft_bzero(&v, sizeof(v));
    if (value_exist(value) && value->type == array)
    {
        if (check_vector((t_json_array *)value->ptr))
            v = new_vector((t_json_array *)value->ptr);
    }
    return (v);
}