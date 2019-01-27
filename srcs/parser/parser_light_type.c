/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:13:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 19:16:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "json_types.h"
#include "json_getter.h"

#include "parser.h"
#include "object.h"

#include "libft.h"

/*
** TODO: improve error handling
*/

t_light_type parser_light_type(t_json_value *value)
{
    t_json_object *o;
    t_json_value *v;
    t_json_string *s;

    if (value->type != object)
        exit(-1);
    o = (t_json_object *)value->ptr;
    v = getter_by_key(o, "type");
    if (value_exist(v) == false || v->type != string)
        exit(-1);
    s = v->ptr;
    if (ft_strequ(s->ptr, "point"))
        return (POINT);
    else if (ft_strequ(s->ptr, "directional"))
        return (DIRECTIONAL);
    else if (ft_strequ(s->ptr, "parallel"))
        return (PARALLEL);
    else
        exit(-1);
}