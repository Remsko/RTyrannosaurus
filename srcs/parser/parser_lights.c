/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:29:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 00:35:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "light.h"

#include "json_types.h"

t_light *parser_lights(t_json_value *value)
{
    t_light *lights;

    if ((lights = (t_light *)malloc(sizeof(t_light))) == NULL)
        return (NULL);
    (void)value;
    return (lights);
}