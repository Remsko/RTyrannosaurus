/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:25:12 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:31:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "light.h"
#include "parser.h"

void *parser_point(t_json_object *o)
{
    t_point *point;

    if ((point = (t_point *)malloc(sizeof(t_point))) == NULL)
        return (NULL);
    point->source = parser_vector(getter_by_key(o, "source"));
    return ((void *)point);
}