/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:55 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:27:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parser.h"

#include "json_types.h"

double parser_double(t_json_value *value)
{
    if (value == NULL || value->ptr == NULL)
        return (0.0);
    return (value_to_double(value->ptr, value->type));
}