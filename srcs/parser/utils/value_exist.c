/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:36:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:37:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "json_types.h"

bool value_exist(t_json_value *value)
{
    return (value != NULL && value->ptr != NULL);
}