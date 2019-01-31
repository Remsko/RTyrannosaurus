/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:55:59 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:19:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parser.h"

#include "json_types.h"

#include "libft.h"

t_color parser_color(t_json_value *value)
{
    t_json_array *a;
    t_color color;

    ft_bzero((void *)&color, sizeof(t_color));
    if (value_exist(value) && value->type == array)
    {
        a = (t_json_array *)value->ptr;
        if (a->len == 3)
        {
            color.r = parser_double(a->value[0]);
            color.g = parser_double(a->value[1]);
            color.b = parser_double(a->value[2]);
        }
    }
    return (color);
}