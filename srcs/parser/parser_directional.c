/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_directional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:33:48 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:34:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "light.h"
#include "parser.h"

void *parser_directional(t_json_object *o)
{
    t_directional *directional;

    if ((directional = (t_directional *)malloc(sizeof(t_directional))) == NULL)
        return (NULL);
    directional->source = parser_vector(getter_by_key(o, "source"));
    directional->direction = parser_vector(getter_by_key(o, "normal"));
    return ((void *)directional);
}