/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parallel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:31:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:34:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "light.h"
#include "parser.h"

void *parser_parallel(t_json_object *o)
{
    t_parallel *parallel;

    if ((parallel = (t_parallel *)malloc(sizeof(t_parallel))) == NULL)
        return (NULL);
    parallel->source = parser_vector(getter_by_key(o, "source"));
    parallel->normal = parser_vector(getter_by_key(o, "direction"));
    return ((void *)parallel);
}