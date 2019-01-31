/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:54:58 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:19:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parser.h"

#include "json_parser.h"

#include "libft.h"

t_vector parser_vector(t_json_value *value)
{
    t_json_array *a;
    t_vector vector;

    ft_bzero((void *)&vector, sizeof(t_vector));
    if (value_exist(value) && value->type == array)
    {
        a = (t_json_array *)value->ptr;
        if (a->len == 3)
        {
            vector.x = parser_double(a->value[0]);
            vector.y = parser_double(a->value[1]);
            vector.z = parser_double(a->value[2]);
        }
    }
    return (vector);
}