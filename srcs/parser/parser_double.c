/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:55 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 11:14:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parser.h"

#include "json_types.h"

static double value_to_double(void *ptr, t_json_value_type type)
{
    if (type == integer)
        return ((double)*(int *)ptr);
    else if (type == number)
        return ((double)*(double *)ptr);
    return (0.0);
}

double parser_double(t_json_value *value)
{
    if (value_exist(value) == false)
        return (0.0);
    return (value_to_double(value->ptr, value->type));
}